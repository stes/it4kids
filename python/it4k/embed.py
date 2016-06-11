from .app import App, mainApp
from .entity import Entity
from .tools import background
import pyglet
pyglet.options['shadow_window'] = False
pyglet.options['debug_gl'] = False
from pyglet import gl

class EmbedApp(App):

    def init_context(self):
        context = FakeContext()
        context.set_current()
        self.window = None
    
    def add_entity(self, entity):
        # TODO: use identifier instead of class name
        entity.batch = self.batch
        name = entity.__class__.__name__
        ents = [ind for ind,val in enumerate(self.entities) if val.__class__.__name__ == name]
        if ents: # replace existing entity
            entity.set_data(self.entities[ents[0]].data)
            for e in ents:
                self.entities[e].clean()
                del self.entities[e]
            self.entities.append(entity)
        else: # add new
            super().add_entity(entity)

    def draw(self):
        self.dispatch_event('on_draw')

    def resize(self, width, height):
        self.dispatch_event('on_resize', width, height)

    def mouse_press(self, x, y, buttons, modifiers):
        self.dispatch_event('on_mouse_press', x, y, pyglet.window.mouse.LEFT, modifiers)

    def mouse_release(self, x, y, buttons, modifiers):
        self.dispatch_event('on_mouse_release', x, y, pyglet.window.mouse.LEFT, modifiers)

    def mouse_drag(self, x, y, dx, dy, buttons, modifiers):
        self.dispatch_event('on_mouse_drag', x, y, dx, dy, pyglet.window.mouse.LEFT, modifiers)

EmbedApp.register_event_type('on_draw')
EmbedApp.register_event_type('on_resize')
EmbedApp.register_event_type('on_mouse_press')
EmbedApp.register_event_type('on_mouse_release')
EmbedApp.register_event_type('on_mouse_drag')

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

def init():
    global mainApp
    if not mainApp:
        mainApp = EmbedApp()
    return mainApp
