#!/usr/bin/env python3

# Filename: subscriber_auto_reply_solved.py
# Author: Adam Fabo
# Last edit: 24.4.2023
# License: Feel free to use this code in any way, shape or form
# University: FIT, BUT, Brno, Czech republic
# This file is a part of authors bachelors thesis
# Description: File contains finished code that automatically replies with custom message when message "Hello" appears at /shared_chatter topic

# Import everything important
import rospy
from std_msgs.msg import String


# Callback function that is called when subscriber gets data
def callback(data):
    # Display the received data
    rospy.loginfo("Received data: %s", data.data)

    """********************************************
    Modify this callback function in a way, that it makes auto-reply when receives word Hello

    1. For checking if word Hello is contained in received message use:
        if "Hello" in str(data.data):
    
    2. If Hello is found in received message create new publisher that sends String messages into /shared_chatter topic, using:
        pub = rospy.Publisher()
        - make queue_size non zero value

    3. Since it takes a while for ROS to connect created publisher to given topic, before sending any message
       it needs to be ensured that publisher is connected
       Use following code, that waits until publisher is conencted:
            
            while pub.get_num_connections() < 1:
            pass  

    4. Reply with "Hello" from your own language, using function:
        pub.publish()

    ********************************************"""

    if "Hello" in str(data.data):

        pub = rospy.Publisher("/shared_chatter", String, queue_size=10)

        while pub.get_num_connections() < 1:
            pass

        pub.publish("Bonjour")

    """ ********************************************
    Do not edit code under this line
    ******************************************** """


# Start of the program
if __name__ == "__main__":
    # Initialize the node
    rospy.init_node("Basic_Subscriber", anonymous=True)

    # Create subscriber that subscribes messages from topic "/chatter" of type String
    # callback function is called when message is received
    rospy.Subscriber("/shared_chatter", String, callback)

    # Keep the node alive
    rospy.spin()
