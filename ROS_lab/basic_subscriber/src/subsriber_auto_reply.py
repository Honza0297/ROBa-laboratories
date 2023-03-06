#!/usr/bin/env python3

# todo first comment

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
    
    2. If Hello is found in received message create new publisher that sends String messages into /chatter topic, using:
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
