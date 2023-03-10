#!/usr/bin/env python3

# todo first comment

# Import everything important
import rospy
from std_msgs.msg import String

# Start of the program
if __name__ == "__main__":

    # Initialize the node
    rospy.init_node("Basic_Publisher", anonymous=True)

    # Create publisher that sends messages to topic "/chatter" and message type is String
    pub = rospy.Publisher("/shared_chatter", String, queue_size=10)

    # Set message speed to 2Hz
    r = rospy.Rate(2)

    # Infinite loop while ROS is running
    while not rospy.is_shutdown():
        """********************************************
        Edit code below, so that it sends message give by user input

        1. Get the user input with function input("Write your message here: ")
            - Save result from this function into variable
            - Set this variable to be sent in pub.publish() function
        ********************************************"""

        # Send your own custom message
        pub.publish("Your message here")

        """ ********************************************
        Do not edit code under this line
        ******************************************** """

        # Sleep for a given time
        r.sleep()
