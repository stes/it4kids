import pyglet
import math, time
from .tools import *

class Entity(pyglet.event.EventDispatcher):
    
    _speed = 40
    
    def __init__(self, img_file, group=foreground, draggable=True):
        self.group = group
        image = pyglet.image.load(img_file).get_texture()
        image.anchor_x = image.width / 2
        image.anchor_y = image.height / 2
        self.sprite = pyglet.sprite.Sprite(image, group=self.group)
        self.draggable = draggable
        self.handlers = 0
    
    def set_data(self, data):
        self.data = data
        self.invalidate(False)
    
    def check_pos(self, x, y):
        tmpx = x - self.data.x - app_size[0] / 2
        tmpy = y - self.data.y - app_size[1] / 2
        x = tmpx * math.cos(math.radians(self.data.rotation)) - tmpy * math.sin(math.radians(self.data.rotation)) + self.sprite.width / 2
        y = tmpx * math.sin(math.radians(self.data.rotation)) + tmpy * math.cos(math.radians(self.data.rotation)) + self.sprite.height / 2
        if x > 0 and y > 0 and x < self.sprite.width and y < self.sprite.height:
            data = get_pixel(self.sprite.image, int(x), int(y))
            return data[3] > 0
        return False
    
    def move(self, x, y):
        self.data.x += x
        self.data.y += y
    
    def move_to(self, x, y):
        self.data.x = x - app_size[0] / 2
        self.data.y = y - app_size[1] / 2
    
    def world_move_to(self, x, y):
        self.data.x = x
        self.data.y = y
    
    def set_group(self, group=None):
        if group:
            self.sprite.group = group
        else:
            self.sprite.group = self.group
    
    def clean(self):
        for i in range(self.handlers):
            self.pop_handlers()
    
    def register(self, *args, **kwargs):
        self.push_handlers(*args, **kwargs)
        self.handlers += 1
    
    def invalidate(self, running=True):
        self.sprite.x = self.data.x + app_size[0] / 2
        self.sprite.y = self.data.y + app_size[1] / 2
        self.sprite.rotation = self.data.rotation
        if running:
            if self._speed > 0:
                time.sleep(1/self._speed)
            hook()
    
    def __getx(self):
        return self.data.x
    
    def __gety(self):
        return self.data.y
    
    def __setx(self, val):
        self.data.x = val
    
    def __sety(self, val):
        self.data.y = val
            
    x = property(__getx, __setx)
    y = property(__gety, __sety)
    
    # block events
    def start(self):
        self.dispatch_event('on_start')
    
    def click(self, x, y):
        if self.check_pos(x, y):
            self.dispatch_event('on_interaction', 'clicked')
    
    # block methods
    def forward(self, len):
        self.data.x += len * math.cos(math.radians(self.data.rotation))
        self.data.y += len * math.sin(-math.radians(self.data.rotation))
        hook()
    
    def turnRight(self, degrees):
        self.data.rotation += degrees
        hook()
    
    def turnLeft(self, degrees):
        self.data.rotation -= degrees
        hook()
    
    def gotoXY(self, x, y):
        self.world_move_to(x, y)
        hook()
    
    def doGlide(self, seconds, x, y):
        steps = int(seconds * self._speed)
        if steps > 0:
            diffX = (x - self.data.x) / steps
            diffY = (y - self.data.y) / steps
            for i in range(steps):
                self.move(diffX, diffY)
                self.invalidate() # animation
        self.world_move_to(x, y)
        self.invalidate(False)
        hook()
    
    def bounceOffEdge(self):
        edge = ""
        min = 0
        rad = math.radians(self.data.rotation)
        width = self.sprite.width #math.fabs(math.cos(rad)) * self.sprite.width + math.fabs(math.sin(rad)) * self.sprite.height
        height = self.sprite.height #math.fabs(math.sin(rad)) * self.sprite.width + math.fabs(math.cos(rad)) * self.sprite.height
        left = width / 2 - app_size[0] / 2
        bottom = height / 2 - app_size[1] / 2
        right = app_size[0] / 2 - width / 2
        top = app_size[1] / 2 - height / 2
        if self.data.x - left < min:
            edge = "left"
            min = self.data.x - left
        if self.data.y - bottom < min:
            edge = "bottom"
            min = self.data.y - bottom
        if right - self.data.x < min:
            edge = "right"
            min = right - self.data.x
        if top - self.data.y < min:
            edge = "top"
            min = top - self.data.y
        
        dx = math.cos(rad)
        dy = math.sin(-rad)
        
        if edge == "left":
            self.data.x = left
            dx *= -1
        if edge == "bottom":
            self.data.y = bottom
            dy *= -1
        if edge == "right":
            self.data.x = right
            dx *= -1
        if edge == "top":
            self.data.y = top
            dy *= -1
        
        self.data.rotation = math.degrees(math.atan2(-dy, dx))
        hook()
    
    def setDirection(self, direction):
        rot = {"left": 180, "right": 0, "down": 90, "up": 270}
        if direction in rot:
            self.data.rotation = rot[direction]
        hook()
    
    def wait(self, sec):
        self.invalidate(False)
        time.sleep(sec)
        hook()

Entity.register_event_type('on_start')
Entity.register_event_type('on_interaction')
