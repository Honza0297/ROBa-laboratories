#!/usr/bin/env python3
  
# todo top comment

# Import everything important
import rospy
from geometry_msgs.msg import Twist

# Pygame neede for keyboard control
import pygame
from pygame.locals import *

# Initialize pygame window
pygame.init()
screen = pygame.display.set_mode((640, 480))
pygame.display.set_caption('Pygame - Trilobot')
pygame.mouse.set_visible(1)



def main():
        # Initialize the node
        rospy.init_node('trilobot_arrow_control', anonymous=True)

        # Create publisher that sends messages to topic "/cmd_vel" and message type is Twist
        pub = rospy.Publisher('/cmd_vel', Twist, queue_size=500)


        while not rospy.is_shutdown():			

            # Create new Twist message instace
            message = Twist()

            # get pygame events
            pygame.event.get()
            # get all pressed keys
            keys = pygame.key.get_pressed()

            """********************************************
            Write logic that controls trilobot movement with keyboard press

            1. Check what key is pressed
                - Pressed keys are stored in dictionary called keys
                - If key is pressed, value is True
                - Acces value using: K_UP, K_DOWN, K_LEFT, K_RIGHT 
                - Sample access: keys[K_UP]

            2. Based on which key is pressed set speed of the trilobot
                - If UP or DOWN arrow is pressed, set message.linear.x to 0.3 or -0.3
                - If LEFT or RIGHT arrow is pressed, set message.angular.z to 1 or -1

            3. Publish this message
                - Dont forget to wait for given time, using rospy.sleep(0.05) 

            BONUS - Make Trilobot to go faster when shift is pressed. Hint: keys[K_LSHIFT]
            ********************************************"""





            """ ********************************************
            Do not edit code under this line
            ******************************************** """


if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
