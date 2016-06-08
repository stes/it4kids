import pyglet
pyglet.options['shadow_window'] = False
pyglet.options['debug_gl'] = False
from pyglet import gl
from .tools import *
from .entity import Entity

mainApp = None

class EntityData:
    def __init__(self):
        self.x = 0
        self.y = 0
        self.rotation = 0
        self.costume = ""
        self.visible = True

class App(pyglet.event.EventDispatcher):

    _scale = 1

    def __init__(self):
        self.init_context()
        self.batch = pyglet.graphics.Batch()
        self.dragging = None
        self.state = app_state
        self.mouse_pressed = False # TODO: rework this
        
        self.entities = []
        self.entity_data = {}
    
    def init_context(self):
        self.window = pyglet.window.Window(resizable=True)
        self.window.push_handlers(
            on_draw=self.on_draw,
            on_resize=self.on_resize,
            on_mouse_press=self.on_mouse_press,
            on_mouse_release=self.on_mouse_release,
            on_mouse_drag=self.on_mouse_drag,
        )
    
    def add_entity(self, entity):
        entity.batch = self.batch
        name = entity.__class__.__name__
        if name not in self.entity_data:
            self.entity_data[name] = EntityData()
        entity.set_data(self.entity_data[name])
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
        self.state.stopping = True
        for thread in self.state.running:
            thread.join()
        self.state.stopping = False
        del self.state.running[:]
    
    def update(self):
        self.state.running = [t for t in self.state.running if t.is_alive()]
    
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
            self.state.paused.set()
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
            self.dragging.invalidate(False)
        elif self.mouse_pressed:
            for entity in self.entities:
                if entity.draggable and entity.check_pos(x, y):
                    self.dragging = entity
                    self.dragging.set_group(overlay)
                    self.state.paused.clear()
                    break
    
    def on_resize(self, width, height):
        screenratio = width / height
        appratio = app_size[0] / app_size[1]
        gl.glViewport(0, 0, width, height)
        gl.glMatrixMode(gl.GL_PROJECTION)
        gl.glLoadIdentity()
        if screenratio < appratio:
            App._scale = width/app_size[0]
            gl.glOrtho(0, app_size[0], 0, app_size[0]/screenratio, -1, 1)
        else:
            App._scale = height/app_size[1]
            gl.glOrtho(0, app_size[1]*screenratio, 0, app_size[1], -1, 1)
        gl.glMatrixMode(gl.GL_MODELVIEW)
        return True
