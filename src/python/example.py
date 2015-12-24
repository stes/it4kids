import pyglet
import it4k

def init(create_window=False):
	myApp = it4k.App('Assets/Backgrounds/desert.gif', create_window=create_window)
	myApp.add_entity(it4k.Entity(pyglet.resource.image('Assets/Costumes/dog2-a.png')))
	myApp.add_entity(it4k.Entity(pyglet.resource.image('Assets/Costumes/dragon1-a.png')))

if  __name__ ==  "__main__":
	init(True)
	pyglet.app.run()
