#!/usr/bin/env python3

# todo first comment

# Import everything important
import rospy
from std_msgs.msg import String


# Callback function that is called when subscriber gets data
def callback(data):
    rospy.loginfo("Received data: %s", data.data)


# Start of the program
if __name__ == '__main__':
    # tell ROS name of this node
    rospy.init_node('Basic_Subscriber', anonymous=True)

    # Create subscriber that subscribes messages from topic "/chatter" of type String
    # callback function is called when message is received
    rospy.Subscriber("/chatter", String, callback)
    rospy.spin()
