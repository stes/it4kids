from pyglet.gl import *

# Direct OpenGL commands to this window.
window = pyglet.window.Window()
while (1):
    pass
@window.event
def on_draw():
    glClear(GL_COLOR_BUFFER_BIT)
    glLoadIdentity()
    glBegin(GL_TRIANGLES)
    glVertex2f(0, 0)
    glVertex2f(window.width, 0)
    glVertex2f(window.width, window.height)
    glEnd()

    pyglet.app.run()
