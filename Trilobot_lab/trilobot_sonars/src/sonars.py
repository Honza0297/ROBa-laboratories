#!/usr/bin/env python3

# todo first comment

# Import everything important

import rospy
from trilobot.msg import Sonar_data


# Callback function that takes in data from sonar
def callback(sonar_data: Sonar_data):

    """********************************************
    Write code that will print data from sonar

    1. Print sonar_data using rospy.loginfo() function

    2. Print only data from front sonar
        - test your implementation by placing obstacle in front of the sonar
    ********************************************"""



def main():
    """********************************************
    Write subscriber that reads data from trilobots sonars

    1. Initialize the node by running function rospy.init_node().
        - Choose custom node name, set anonymous=True

    2. Create subscriber that reads sonar data from triboots sonars
        - Use rospy.Subscriber() function
        - Topic to read from is /trilobot/sonar_data
        - Message type is Sonar_data
        - callback function is callback

    3. Keep the node alive
        - use function rospy.spin()
    ********************************************"""






    """ ********************************************
    Do not edit code under this line
    ******************************************** """


if __name__ == "__main__":
    try:
        main()
    except rospy.ROSInterruptException:
        pass
