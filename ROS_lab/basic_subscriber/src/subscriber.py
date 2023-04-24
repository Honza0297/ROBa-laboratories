#!/usr/bin/env python3

# Filename: subscriber.py
# Author: Adam Fabo
# Last edit: 24.4.2023
# License: Feel free to use this code in any way, shape or form
# University: FIT, BUT, Brno, Czech republic
# This file is a part of authors bachelors thesis
# Description: File contains unfinished code that should receive String data from /chatter topic

# Import everything important
import rospy
from std_msgs.msg import String


# Callback function that is called when subscriber gets data
def callback(data):
    rospy.loginfo("Received data: %s", data.data)


# Start of the program
if __name__ == "__main__":
    """********************************************
    Write simple subscriber that subscribes to topic /chatter and displays received messages

    1. Init the newly created node with function rospy.init_node("Node_name", anonymous=True)
        - Set your own custom node name
        - Set anonymous=True

    2. Create subscriber that subsrcribes to topic /chatter, message type is String:
        rospy.Subscriber("/chatter", String, callback)
        - Set topic to /chatter
        - Set message to String
        - Set the callback function to be callback

    3. Call function rospy.spin() to keep the node alive



    Write your below this line (write it inside of the if __name__ == '__main__': condition)
    ********************************************"""
