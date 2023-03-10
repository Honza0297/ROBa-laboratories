#!/usr/bin/env python3
  

# Import everything important
import rospy
from trilobot.msg import Sonar_data
from geometry_msgs.msg import Twist

# Global variables definitions
distance = 45       # Distance read from sonar
mode = "forward"    # Mode of the robot: forward/rotate



# Callback function that sets mode to forward
def timer_callback(event):
    global mode
    mode = "forward"
    rospy.loginfo(f"Mode has been set to forward")


# Callback function that is called when data from sensors are received
def callback(sonar_data:Sonar_data):
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
    rospy.init_node('trilobot_navigation', anonymous=True)

    # Create publisher that sends messages to topic "/cmd_vel" and message type is Twist
    pub = rospy.Publisher('/cmd_vel', Twist, queue_size=500)

    # Create subscriber that subscribes messages from topic "/trilobot/sonar_data" of type Sonar_data
    # callback function is called when message is received
    rospy.Subscriber("/trilobot/sonar_data", Sonar_data, callback)

    # Infinite loop while ROS is running
    while not rospy.is_shutdown():

        """********************************************
        Todo
        ********************************************"""
                

        message = Twist()
        

        if mode == "forward":
            # If there is no obstacle in front of the robot, go forward
            if distance >= 40:  
                message.linear.x  = 0.15
                message.angular.z = 0
            
            # If obstacle is found, set mode to "rotate" and set rotation for 1 second
            else:
                # Debug Info
                rospy.loginfo("Found obstacle")   

                # Stop the robot
                message.linear.x  = 0
                message.angular.z = 0

                # Set mode to "rotate"
                mode = "rotate"

                # Set timer to 1 second, after one second set mode to "forward"
                rospy.Timer(rospy.Duration(1), timer_callback, oneshot= True)

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


  
if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
