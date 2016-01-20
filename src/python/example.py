import pyglet
import it4k
import sys, inspect

class Dog(it4k.Entity):
	
	def __init__(self):
		image = pyglet.resource.image('Assets/Costumes/dog2-a.png')
		it4k.Entity.__init__(self, image)
	
	def receiveGO(self):
		self.forward(10)
		for a in range(10):
			self.forward(10)
			self.turnRight(15)
		self.turnLeft(15)

class Dragon(it4k.Entity):
	
	def __init__(self):
		image = pyglet.resource.image('Assets/Costumes/dragon1-a.png')
		it4k.Entity.__init__(self, image)
	
	def receiveGO(self):
		self.forward(10)
		for a in range(10):
			self.forward(10)
			self.turnRight(15)
		self.turnLeft(15)

def init(create_window=False):
	myApp = it4k.App('Assets/Backgrounds/desert.gif', create_window=create_window)
	entities = inspect.getmembers(sys.modules[__name__], inspect.isclass)
	for entity in entities:
		myApp.add_entity((entity[1])())

if  __name__ ==  "__main__":
	init(True)
	pyglet.app.run()
