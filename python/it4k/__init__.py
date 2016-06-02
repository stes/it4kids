from .app import App, mainApp
from .entity import Entity
from .tools import block, background

def init(background_file):
    global mainApp
    if mainApp:
        mainApp.reset()
    else:
        mainApp = App()
    mainApp.add_entity(Entity(background_file, background, draggable=False))  # TODO: store this
    return mainApp
