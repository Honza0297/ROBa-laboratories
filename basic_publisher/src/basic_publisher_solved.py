#!/usr/bin/env python3

# todo first comment

# Import everything important
import rospy
from std_msgs.msg import String

# Start of the program
if __name__ == '__main__':
    # tell ROS name of this node
    rospy.init_node('Basic_Publisher')

    # Create publisher that sends messages to topic "/chatter" and message type is String
    pub = rospy.Publisher('/chatter', String, queue_size=10)

    # Set message speed to 2Hz
    r = rospy.Rate(2)

    # Infinite loop while ROS is running
    while not rospy.is_shutdown():
        # Send your own custom message
        pub.publish("Your message here")
        # Sleep for a given time
        r.sleep()
