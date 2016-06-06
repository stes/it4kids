from .app import App, mainApp
from .entity import Entity
from .tools import block, background

def init():
    global mainApp
    if mainApp:
        mainApp.reset()
    else:
        mainApp = App()
    return mainApp
