import rospy
from std_msgs.msg import String#Callback function to print the subscribed data on the terminal
from geometry_msgs.msg import Twist

import pygame, time
from datetime import datetime
from pygame.locals import *




pygame.init()
screen = pygame.display.set_mode((640, 480))
pygame.display.set_caption('Pygame Keyboard Test')
pygame.mouse.set_visible(1)



def messagePublisher():
	print("I am here")
	message_publisher = rospy.Publisher('/cmd_vel', Twist, queue_size=50)    #initialize the Publisher node. 

	#Setting anonymous=True will append random integers at the end of our publisher node

	rospy.init_node('arrows_bad_boy', anonymous=True)    #publishes at a rate of 2 messages per second
	rate = rospy.Rate(10)    #Keep publishing the messages until the user interrupts 

	while not rospy.is_shutdown():
		message = Twist()
		message.linear.x = 0.0

		pygame.event.get()
		keys=pygame.key.get_pressed()
		print(datetime.now())
		#print(keys)
		
		if keys[K_UP]:
			print("pressed left")
			message.linear.x = 0.3
		if keys[K_DOWN]:
			message.linear.x = -0.3
			print("pressed right")
		if keys[K_LEFT]:
			message.angular.z = 1
			print("pressed right")
		if keys[K_RIGHT]:
			message.angular.z = -1
			print("pressed right")
		print("Running")
		message_publisher.publish(message)    #rate.sleep() will wait enough until the node publishes the     message to the topic
		#print(datetime.datetime.now())
		#rospy.loginfo(message)    #publish the message to the topic
		rate.sleep()


if __name__ == '__main__':
    try:
        messagePublisher()
    #capture the Interrupt signals
    except rospy.ROSInterruptException:
        pass

