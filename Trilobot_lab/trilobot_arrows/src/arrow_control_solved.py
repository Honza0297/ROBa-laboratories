#!/usr/bin/env python3
  
# todo top comment

# Import everything important
import rospy
from geometry_msgs.msg import Twist

# Pygame needed for keyboard control
import pygame
from pygame.locals import *



# Draw image at screen
def draw_image(screen):
        # create a surface object, image is drawn on it.
        imp = pygame.image.load("Arrows_img.jpg").convert()
        # Using blit to copy content from one surface to other
        screen.blit(imp, (0, 0))
        # paint screen one time
        pygame.display.flip()


# Initialize pygame window
pygame.init()
screen = pygame.display.set_mode((640, 480))
pygame.display.set_caption('Pygame - Trilobot')
pygame.mouse.set_visible(1)
draw_image(screen)



def main():
        # Initialize the node
        rospy.init_node('trilobot_arrow_control', anonymous=True)

        # Create publisher that sends messages to topic "/cmd_vel" and message type is Twist
        pub = rospy.Publisher('/cmd_vel', Twist, queue_size=500)


        while not rospy.is_shutdown():			

            # Create new Twist message instace
            message = Twist()

            # Get pygame events
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    # If cross has been clicked, exit application
                    exit()
                if event.type == pygame.VIDEORESIZE:
                    # If window has been resized, draw image again
                    draw_image(screen)
            # Get all pressed keys
            keys = pygame.key.get_pressed()

            """********************************************
            Write logic that controls trilobot movement with keyboard press

            1. Check what key is pressed
                - Pressed keys are stored in dictionary key
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
            multiplier = 1

            # If left shift is pressed
            if keys[K_LSHIFT]:
                rospy.loginfo("UP arrow pressed")   
                multiplier = 5

            # If up arrow is pressed
            if keys[K_UP]:
                rospy.loginfo("UP arrow pressed")   
                message.linear.x = 0.3 * multiplier

            # If down arrow is pressed
            if keys[K_DOWN]:
                rospy.loginfo("DOWN arrow pressed")  
                message.linear.x = -0.3 * multiplier

            # If left arrow is pressed
            if keys[K_LEFT]:
                rospy.loginfo("LEFT arrow pressed")  
                message.angular.z = 1 * multiplier

            # If up right is pressed
            if keys[K_RIGHT]:
                rospy.loginfo("RIGHT arrow pressed")  
                message.angular.z = -1 * multiplier


            # Publish the message
            pub.publish(message)
            # Sleep for given time
            rospy.sleep(0.05) 


            """ ********************************************
            Do not edit code under this line
            ******************************************** """


if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass

