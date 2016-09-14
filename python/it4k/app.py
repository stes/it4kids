import pyglet
# fixes costume change
pyglet.options['graphics_vbo'] = False
pyglet.options['shadow_window'] = False
pyglet.options['debug_gl'] = False
from pyglet import gl
from .tools import *
from .entity import Entity, EntityData

mainApp = None

class App(pyglet.event.EventDispatcher):

    _scale = 1

    def __init__(self):
        self.init_context()
        self.batch = pyglet.graphics.Batch()
        self.dragging = None
        self.state = app_state
        self.mouse_pressed = False # TODO: rework this
        
        gl.glMatrixMode(gl.GL_PROJECTION)
        gl.glLoadIdentity()
        gl.glOrtho(-app_size[0]/2, app_size[0]/2, -app_size[1]/2, app_size[1]/2, -1, 1)
        
        global pen
        pen.init_fbo()
        
        self.entities = []
        
        pen_entity = Entity(layer0, draggable=False)
        pen_entity.add_costume_memory("pen", pen.fbo.texture)
        self.add_entity(pen_entity)
    
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
        entity.set_data(EntityData())
        self.entities.append(entity)
    
    def add_media_path(self, path):
        pyglet.resource.path.append(path)
        pyglet.resource.reindex()
    
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
        global pen
        pen.update()
        gl.glViewport(0, 0, int(app_size[0]*self._scale), int(app_size[1]*self._scale))
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
        if screenratio < appratio:
            self._scale = width/app_size[0]
        else:
            self._scale = height/app_size[1]
        return True
