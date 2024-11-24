#!/usr/bin/env python3

# Filename: navigation_solved.py
# Author: Adam Fabo
# Last edit: 24.4.2023
# License: Feel free to use this code in any way, shape or form
# University: FIT, BUT, Brno, Czech republic
# This file is a part of authors bachelors thesis
# Description: File contains finished code that implements simple navigation algorithm

# Import everything important
import rospy
from trilobot.msg import Sonar_data
from geometry_msgs.msg import Twist

# Global variables definitions
distance = 45  # Distance read from sonar,
mode = "forward"  # Mode of the robot: forward/rotate


# Callback function that sets mode to forward
def timer_callback(event):
    global mode
    mode = "forward"
    rospy.loginfo(f"Mode has been set to forward")


# Callback function that is called when data from sensors are received
def callback(sonar_data: Sonar_data):
    global distance

    """********************************************
    Set global variable distance to be equal to data read from front sonar

    1. Set distance to be data from front sensor

    ********************************************"""

    distance = sonar_data.front
    rospy.loginfo(f"Front sonar distance: {sonar_data.front}")


def main():
    global mode
    global distance

    # Initialize the node
    rospy.init_node("trilobot_navigation", anonymous=True)

    # Create publisher that sends messages to topic "/cmd_vel" and message type is Twist
    pub = rospy.Publisher("/cmd_vel", Twist, queue_size=500)

    # Create subscriber that subscribes messages from topic "/trilobot/sonar_data" of type Sonar_data
    # callback function is called when message is received
    rospy.Subscriber("/trilobot/sonar_data", Sonar_data, callback)

    # Infinite loop while ROS is running
    while not rospy.is_shutdown():

        # Twist message which will be sent to trilobot
        message = Twist()

        """********************************************
        Create simple algorithm for avoiding obstacles. Robot goes straight and if detects obstacle
        by front sonar rotates. After that continues in straight line again.

        Distance from front sonar is stored in global variable distance (you dont have to implement subscriber)

        Trilobot will have 2 MODES - "forward" and "rotate" (mode is stored in global variable mode)

        MODE "forward":
        1. If distance is greater than 40 cm make robot go straight by setting speed as following:
            message.linear.x  = 0.15
            message.angular.z = 0
        2. Else if distance is lesser than 40 cm make robot stop and set mode to "rotate" for 1 second
            - Stop the robot by setting message.linear.x to 0
            - set mode to "rotate"
            - Call timer that will change "rotate" mode into "forward" after 1 second (Robot will be therefore rotating 1 second), using: 
              
              rospy.Timer(rospy.Duration(1), timer_callback, oneshot = True) # Timer call function timer_callback once after 1 second
                                                                             # Function timer_callback changes mode into "forward", it is already implemented above

        MODE "rotate":
        1. Make robot rotate
            - Set speed as following:
                message.linear.x  = 0
                message.angular.z = 1
        
        Common code:
        1. Dont forget to send the message
            - Use: pub.publish(message)
            - Also slow the program using: rospy.sleep(0.05) 

        ********************************************"""

        if mode == "forward":
            # If there is no obstacle in front of the robot, go forward
            if distance >= 40:
                message.linear.x = 0.15
                message.angular.z = 0

            # If obstacle is found, set mode to "rotate" and set rotation for 1 second
            else:
                # Debug Info
                rospy.loginfo("Found obstacle")

                # Stop the robot
                message.linear.x = 0
                message.angular.z = 0

                # Set mode to "rotate"
                mode = "rotate"

                # Set timer to 1 second, after one second set mode to "forward"
                rospy.Timer(rospy.Duration(1), timer_callback, oneshot=True)

        elif mode == "rotate":
            # Rotate the robot
            message.linear.x = 0
            message.angular.z = 1

        # Publish the message
        pub.publish(message)
        # Sleep for given time
        rospy.sleep(0.05)

        """ ********************************************
        Do not edit code under this line
        ******************************************** """


if __name__ == "__main__":
    try:
        main()
    except rospy.ROSInterruptException:
        pass
