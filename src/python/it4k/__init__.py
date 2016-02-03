from __future__ import division
import pyglet
pyglet.options['shadow_window'] = False
pyglet.options['debug_gl'] = False
from pyglet import gl
from struct import unpack
from threading import Thread
import os, math, time

background = pyglet.graphics.OrderedGroup(0)
foreground = pyglet.graphics.OrderedGroup(1)
overlay = pyglet.graphics.OrderedGroup(2)

mainApp = None

# TODO: rework this
class SigStop(Exception):
    pass

def stop_func(func, *args, **kwargs):
	try:
		func(*args, **kwargs)
	except SigStop:
		pass

def block(func):
	def async_func(*args, **kwargs):
		global mainApp
		func_th = Thread(target = stop_func, args = (func,) + args, kwargs = kwargs)
		mainApp.running.append(func_th)
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

class Entity(pyglet.event.EventDispatcher):
	
	_speed = 40
	
	def __init__(self, img_file, group=foreground, draggable=True):
		self.group = group
		image = pyglet.resource.image(img_file)
		image.anchor_x = image.width / 2
		image.anchor_y = image.height / 2
		self.sprite = pyglet.sprite.Sprite(image, group=self.group)
		self.draggable = draggable
		self.world_move_to(0, 0)
		self.handlers = 0
	
	def check_pos(self, x, y):
		tmpx = x - self.sprite.x
		tmpy = y - self.sprite.y
		x = tmpx * math.cos(math.radians(self.sprite.rotation)) - tmpy * math.sin(math.radians(self.sprite.rotation)) + self.sprite.width / 2
		y = tmpx * math.sin(math.radians(self.sprite.rotation)) + tmpy * math.cos(math.radians(self.sprite.rotation)) + self.sprite.height / 2
		if x > 0 and y > 0 and x < self.sprite.width and y < self.sprite.height:
			data = get_pixel(self.sprite.image, int(x), int(y))
			return data[3] > 0
		return False
	
	def move(self, x, y):
		self.sprite.x += x
		self.sprite.y += y
	
	def move_to(self, x, y):
		self.sprite.x = x
		self.sprite.y = y
	
	def world_move_to(self, x, y):
		self.sprite.x = (x + App._size[0] / 2)
		self.sprite.y = (y + App._size[1] / 2)
	
	def set_group(self, group=None):
		if group:
			self.sprite.group = group
		else:
			self.sprite.group = self.group
	
	def clean(self):
		for i in range(self.handlers):
			self.pop_handlers()
	
	def register(self, *args, **kwargs):
		self.push_handlers(*args, **kwargs)
		self.handlers += 1
	
	def wait(self):
		global mainApp
		if mainApp.stopping:
			raise SigStop()
		time.sleep(1/self._speed)
	
	# block events
	def start(self):
		self.dispatch_event('on_start')
	
	def click(self, x, y):
		if self.check_pos(x, y):
			self.dispatch_event('on_click')
	
	# block methods
	def forward(self, len):
		self.sprite.x += len * math.cos(math.radians(self.sprite.rotation))
		self.sprite.y += len * math.sin(-math.radians(self.sprite.rotation))
		self.wait() # animation
	
	def turnRight(self, degrees):
		self.sprite.rotation += degrees
		self.wait() # animation
	
	def turnLeft(self, degrees):
		self.sprite.rotation -= degrees
		self.wait() # animation
	
	def gotoXY(self, x, y):
		self.world_move_to(x, y)
		self.wait() # animation
	
	def doGlide(self, seconds, x, y):
		steps = seconds * self._speed
		diffX = (x + App._size[0] / 2 - self.sprite.x) / steps
		diffY = (y + App._size[1] / 2 - self.sprite.y) / steps
		for i in range(int(steps)):
			self.move(diffX, diffY)
			self.wait() # animation
		self.world_move_to(x, y)

Entity.register_event_type('on_start')
Entity.register_event_type('on_click')

class App(object):

	_scale = 1
	_size = (480, 360)

	def __init__(self, create_window=True):
		if create_window:
			self.window = pyglet.window.Window(resizable=True)
			dispatcher = self.window
		else:
			pyglet.resource.path = [os.getcwd() + '/python']
			pyglet.resource.reindex()
			context = FakeContext()
			context.set_current()
			dispatcher = widget
			self.window = None
		
		dispatcher.push_handlers(
			on_draw=self.on_draw,
			on_resize=widget.on_resize,
			on_mouse_press=self.on_mouse_press,
			on_mouse_release=self.on_mouse_release,
			on_mouse_drag=self.on_mouse_drag,
		)
		
		self.batch = pyglet.graphics.Batch()
		self.dragging = None
		self.mouse_pressed = False # TODO: rework this
		
		self.entities = []
		self.running = []
		self.stopping = False
	
	def add_entity(self, entity):
		entity.sprite.batch = self.batch
		self.entities.append(entity)
	
	def reset(self):
		self.stop()
		for entity in self.entities:
			entity.clean()
		del self.entities[:]
	
	def start(self):
		for entity in self.entities:
			entity.start()
	
	def stop(self):
		self.stopping = True
		for thread in self.running:
			thread.join()
		self.stopping = False
		del self.running[:]
	
	def update(self):
		self.running = [t for t in self.running if t.is_alive()]
	
	def on_draw(self):
		self.update()
		if self.window:
			self.window.clear()
		self.batch.draw()

	def on_mouse_press(self, x, y, buttons, modifiers):
		x /= self._scale
		y /= self._scale
		if buttons & pyglet.window.mouse.LEFT:
			self.mouse_pressed = True
	
	def on_mouse_release(self, x, y, buttons, modifiers):
		x /= self._scale
		y /= self._scale
		if not (buttons & pyglet.window.mouse.LEFT):
			return
		if self.dragging:
			self.dragging.set_group()
			self.dragging = None
		else:
			for entity in self.entities:
				entity.click(x, y)
		self.mouse_pressed = False
	
	def on_mouse_drag(self, x, y, dx, dy, buttons, modifiers):
		x /= self._scale
		y /= self._scale
		dx /= self._scale
		dy /= self._scale
		if not (buttons & pyglet.window.mouse.LEFT):
			return
		if self.dragging:
			self.dragging.move(dx, dy)
		elif self.mouse_pressed:
			for entity in self.entities:
				if entity.draggable and entity.check_pos(x, y):
					self.dragging = entity
					self.dragging.set_group(overlay)
					break

class FakeContext(gl.Context):
	def __init__(self, config=None, context_share=None):
		self.config = config
		self.context_share = context_share
		self.canvas = None
		if context_share:
			self.object_space = context_share.object_space
		else:
			self.object_space = gl.ObjectSpace()
	
	def attach(self, canvas=None):
		pass
	
	def detach(self):
		pass
	
	def set_current(self):
		# XXX not per-thread
		gl.current_context = self
		# XXX
		gl.gl_info.set_active_context()
		gl.glu_info.set_active_context()
		# Implement workarounds
		if not self._info:
			self._info = gl.gl_info.GLInfo()
			self._info.set_active_context()
			for attr, check in self._workaround_checks:
				setattr(self, attr, check(self._info))
		# Release textures and buffers on this context scheduled for deletion.
		# Note that the garbage collector may introduce a race condition,
		# so operate on a copy of the textures/buffers and remove the deleted
		# items using list slicing (which is an atomic operation)
		if self.object_space._doomed_textures:
			textures = self.object_space._doomed_textures[:]
			textures = (gl.GLuint * len(textures))(*textures)
			gl.glDeleteTextures(len(textures), textures)
			self.object_space._doomed_textures[0:len(textures)] = []
		if self.object_space._doomed_buffers:
			buffers = self.object_space._doomed_buffers[:]
			buffers = (gl.GLuint * len(buffers))(*buffers)
			gl.glDeleteBuffers(len(buffers), buffers)
			self.object_space._doomed_buffers[0:len(buffers)] = []

class Widget(pyglet.event.EventDispatcher):
	def on_resize(self, width, height):
		screenratio = width / height
		appratio = App._size[0] / App._size[1]
		gl.glViewport(0, 0, width, height)
		gl.glMatrixMode(gl.GL_PROJECTION)
		gl.glLoadIdentity()
		if screenratio < appratio:
			App._scale = width/App._size[0]
			gl.glOrtho(0, App._size[0], 0, App._size[0]/screenratio, -1, 1)
		else:
			App._scale = height/App._size[1]
			gl.glOrtho(0, App._size[1]*screenratio, 0, App._size[1], -1, 1)
		gl.glMatrixMode(gl.GL_MODELVIEW)
		return True

Widget.register_event_type('on_draw')
Widget.register_event_type('on_resize')
Widget.register_event_type('on_mouse_press')
Widget.register_event_type('on_mouse_release')
Widget.register_event_type('on_mouse_drag')

widget = Widget()

def draw():
	widget.dispatch_event('on_draw')

def resize(width, height):
	widget.dispatch_event('on_resize', width, height)

def mouse_press(x, y, buttons, modifiers):
	widget.dispatch_event('on_mouse_press', x, y, pyglet.window.mouse.LEFT, modifiers)

def mouse_release(x, y, buttons, modifiers):
	widget.dispatch_event('on_mouse_release', x, y, pyglet.window.mouse.LEFT, modifiers)

def mouse_drag(x, y, dx, dy, buttons, modifiers):
	widget.dispatch_event('on_mouse_drag', x, y, dx, dy, pyglet.window.mouse.LEFT, modifiers)
	
def start():
	global mainApp
	if mainApp:
		mainApp.start()

def stop():
	global mainApp
	if mainApp:
		mainApp.stop()

def init(background_file, create_window=True):
	global mainApp
	if mainApp:
		mainApp.reset()
	else:
		mainApp = App(create_window=create_window)
	mainApp.add_entity(Entity(background_file, background, draggable=False))  # TODO: store this
	return mainApp
