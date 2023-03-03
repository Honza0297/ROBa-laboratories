import pygame, time
from pygame.locals import *
pygame.init()
screen = pygame.display.set_mode((640, 480))
pygame.display.set_caption('Pygame Keyboard Test')
pygame.mouse.set_visible(0)


while True:

    #print("doing a function")

    # for event in pygame.event.get():
    #     keys=pygame.key.get_pressed()
    #     #print(keys)
        
    #     if keys[K_LEFT]:
    #         print("pressed left")
    #     if keys[K_RIGHT]:
    #         print("pressed right")

    #     if (event.type == KEYUP) or (event.type == KEYDOWN):
    #         print("key pressed")
    pygame.event.get()
    keys=pygame.key.get_pressed()
    if keys[K_LEFT]:
        print("pressed left")
    if keys[K_RIGHT]:
        print("pressed right")
    time.sleep(0.1)