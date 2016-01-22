import it4k
import sys, inspect

class Dog(it4k.Entity):
	
	def __init__(self):
		it4k.Entity.__init__(self, 'Assets/Costumes/dog2-a.png')
		self.register(on_start=self.receiveGO)
	
	@it4k.block
	def receiveGO(self):
		self.gotoXY(-100, -50)
		self.forward(10)
		for a in range(10):
			self.forward(10)
			self.turnRight(15)
		self.turnLeft(15)

class Dragon(it4k.Entity):
	
	def __init__(self):
		it4k.Entity.__init__(self, 'Assets/Costumes/dragon1-a.png')
		self.register(on_start=self.receiveGO_1)
		self.register(on_start=self.receiveGO_2)
		self.register(on_click=self.clicked)
	
	@it4k.block
	def receiveGO_1(self):
		for a in range(10):
			self.forward(20)
	
	@it4k.block
	def receiveGO_2(self):
		for a in range(10):
			self.turnLeft(15)
	
	@it4k.block
	def clicked(self):
		for a in range(10):
			self.turnRight(15)

def init(create_window=False):
	myApp = it4k.init('Assets/Backgrounds/desert.gif', create_window=create_window)
	entities = inspect.getmembers(sys.modules[__name__], inspect.isclass)
	for entity in entities:
		myApp.add_entity((entity[1])())

def update(dt):
    pass

if  __name__ ==  "__main__":
	import pyglet
	
	init(True)
	it4k.start()
	pyglet.clock.schedule_interval(update, 1/60.0)
	pyglet.app.run()
