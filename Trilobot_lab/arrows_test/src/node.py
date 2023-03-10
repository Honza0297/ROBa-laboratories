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
		multiplier = 1

		# Create new Twist message instace
		message = Twist()

		# get pygame events
		pygame.event.get()
		# get all pressed keys
		keys = pygame.key.get_pressed()

		"""********************************************
		Todo
		********************************************"""

		# If up arrow is pressed
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

