#!/usr/bin/env python3

# Filename: publisher.py
# Author: Adam Fabo
# Last edit: 24.4.2023
# License: Feel free to use this code in any way, shape or form
# University: FIT, BUT, Brno, Czech republic
# This file is a part of authors bachelors thesis
# Description: File contains unfinished code that should send String messages into /chatter topic

# Import everything important
import rospy
from std_msgs.msg import String

# Start of the program
if __name__ == "__main__":

    """********************************************
    Write simple publisher that sends String messages to /chatter topic 2 times per second

    1. Init the newly created node with function rospy.init_node("Node_name", anonymous=True)
        - Set your own custom node name
        - Set anonymous=True

    2. Create publisher that publishes String messages to topic /chatter using function:
        pub = rospy.Publisher('/chatter', String, queue_size=10)
        - Set topic to /chatter
        - Set message to String
        - Set queue size to non-zero value
        - Set the created publisher into variable

    3. Set rate of sending messages to 2 times per second using function: r = rospy.Rate(2)
        - Set rate to 2 messges per second
        - Set the created rate class into variable

    4. Create while loop that will run while ROS master is runnin using: while not rospy.is_shutdown():

    5. Inside of this while loop send your own message using created publisher:
        pub.publish("Your message here")

    6. Inside of this while loop slow down the sending by using function r.sleep()


    Write your below this line (write it inside of the if __name__ == '__main__': condition)
    ********************************************"""
