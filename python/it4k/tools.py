import pyglet
from struct import unpack
from threading import Thread, Event

background = pyglet.graphics.OrderedGroup(0)
foreground = pyglet.graphics.OrderedGroup(1)
overlay = pyglet.graphics.OrderedGroup(2)

app_size = (480, 360)

class custom_range(object):
    def __init__(self, n, func):
        self.i = 0
        self.n = n
        self.func = func

    def __iter__(self):
        return self

    def __next__(self):
        self.func()
        if self.i < self.n:
            i = self.i
            self.i += 1
            return i
        else:
            raise StopIteration()

class AppState(object):
    def __init__(self):
        self.paused = Event()
        self.paused.set()
        self.running = []
        self.stopping = False

app_state = AppState()

# TODO: rework this
class SigStop(Exception):
    pass

def block_wrapper(func, *args, **kwargs):
    try:
        func(*args, **kwargs)
        args[0].invalidate()
    except SigStop:
        pass

def block(func):
    def async_func(*args, **kwargs):
        global app_state
        func_th = Thread(target = block_wrapper, args = (func,) + args, kwargs = kwargs)
        app_state.running.append(func_th)
        func_th.start()
    return async_func

def get_pixel(image, x, y):
    rawimage = image.get_image_data()
    format = 'RGBA'
    pitch = rawimage.width * len(format)
    pixels = rawimage.get_data(format, pitch)
    data = unpack("%iB" % (len(format) * rawimage.width * rawimage.height), pixels)
    index = x * len(format) + y * pitch
    return data[index : (index + len(format))]

def hook():
    if app_state.stopping:
        raise SigStop()
    app_state.paused.wait()
