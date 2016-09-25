from .app import App, mainApp
from .entity import Entity
from .tools import background, calcFunction

def init():
    global mainApp
    if not mainApp:
        mainApp = App()
    return mainApp
