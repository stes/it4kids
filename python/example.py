import pyglet
import it4k

class Stage(it4k.Entity):
    def __init__(self):
        it4k.Entity.__init__(self, it4k.background, draggable=False)
        self.add_costume("desert", "../Assets/Backgrounds/desert.gif")

class sprite(it4k.Entity):
    def __init__(self):
        super().__init__()
        self.add_costume("dog2-a", "../Assets/Costumes/dog2-a.png")
        self.register(on_start=self.receiveGo1)
        self.register(on_interaction=self.receiveInteraction1)

    @it4k.block
    def receiveGo1(self):
        while True:
            self.forward(10)
            self.turnRight(15)
            self.invalidate()
        self.invalidate()

    @it4k.block
    def receiveInteraction1(self, type):
        if type != "clicked":
            return
        self.setDirection("right")
        self.turnRight(20)
        while True:
            self.forward(10)
            self.bounceOffEdge()
            self.invalidate()
        self.invalidate()

def update(dt):
    pass

if __name__ ==  "__main__":
    myApp = it4k.init()
    myApp.add_entity(Stage())
    myApp.add_entity(sprite())
    pyglet.clock.schedule_interval(update, 1/60.0)
    pyglet.app.run()
