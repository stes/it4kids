import pyglet
from pyglet import gl
from struct import unpack
from threading import Thread, Event
import ctypes

background = pyglet.graphics.OrderedGroup(0)
layer0 = pyglet.graphics.OrderedGroup(1)
layer1 = pyglet.graphics.OrderedGroup(2)
overlay = pyglet.graphics.OrderedGroup(3)

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

class FBO:
    def __init__(self, width, height):
        self.fbo = gl.GLuint(0)

        gl.glGenFramebuffers(1, ctypes.byref(self.fbo))
        gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, self.fbo)
        
        self.texture = pyglet.image.Texture.create(width, height)
        gl.glBindTexture(self.texture.target, 0)
        gl.glFramebufferTexture2D(gl.GL_FRAMEBUFFER, gl.GL_COLOR_ATTACHMENT0, gl.GL_TEXTURE_2D, self.texture.id, 0)
        
        draw_buffers = (gl.GLenum * 1)(gl.GL_COLOR_ATTACHMENT0)
        gl.glDrawBuffers(1, draw_buffers)

        assert gl.glCheckFramebufferStatus(gl.GL_FRAMEBUFFER) == gl.GL_FRAMEBUFFER_COMPLETE

        gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, 0)

    def __enter__(self):
        self.current_fbo = (gl.GLint)()
        gl.glGetIntegerv(gl.GL_FRAMEBUFFER_BINDING, self.current_fbo);
        gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, self.fbo)
        gl.glViewport(0, 0, self.texture.width, self.texture.height)

    def __exit__(self, *unused):
        gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, gl.GLuint(self.current_fbo.value))

def hex_to_rgb(value):
    value = value.lstrip('#')
    lv = len(value)
    return tuple(int(value[i:i + lv // 3], 16) for i in range(0, lv, lv // 3))

class Pen:
    class Action:
        Line, Clear = range(2)

    def __init__(self):
        self.fbo = None
        self.pending_actions = []
    
    def init_fbo(self):
        self.fbo = FBO(*app_size)
    
    def add_line(self, line, size, color):
        self.pending_actions.append((Pen.Action.Line, line, size, color))
    
    def clear(self):
        self.pending_actions = [(Pen.Action.Clear,)]
    
    def update(self):
        if self.pending_actions:
            with self.fbo:
                while self.pending_actions:
                    action = self.pending_actions.pop()
                    if action[0] == Pen.Action.Line:
                        gl.glLineWidth(action[2])
                        pyglet.graphics.draw(2, gl.GL_LINES, ('v2f', action[1]), ('c3B', 2*action[3]))
                    else:
                        gl.glClearColor(0, 0, 0, 0)
                        gl.glClear(gl.GL_COLOR_BUFFER_BIT)

pen = Pen()

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
