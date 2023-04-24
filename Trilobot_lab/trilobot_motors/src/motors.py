#!/usr/bin/env python3
  
# Filename: motors.py
# Author: Adam Fabo
# Last edit: 24.4.2023
# License: Feel free to use this code in any way, shape or form
# University: FIT, BUT, Brno, Czech republic
# This file is a part of authors bachelors thesis
# Description: File contains unfinished code that controls motors on robot Trilobot


import rospy
from geometry_msgs.msg import Twist

  
def main():

    """********************************************
    Write publisher that controls trilobots motors

    1. Initialize the node by running function rospy.init_node().
        - Choose custom node name, set anonymous=True

    2. Create publisher that controls trilobots motors
        - Use rospy.Publisher() function
            - Save instance of this publisher into pub variable
        - Topic to write to is /cmd_vel
        - Message type is Twist
        - Set queue_size=500

    3. Create new Twist object that will be the message
        - Create instance by msg = Twist()
        - Set motor linear speed to 0.2 by msg.linear.x = 0.2
    
    4. Create while loop that will run while ROS master is runnin using: while not rospy.is_shutdown():

    5. Inside of this while loop send your own message using created publisher:
        pub.publish(msg)

    6. Inside of this while loop slow down the sending by using function rospy.sleep(0.02)


    BONUS: Experiment with different speeds, and try to use linear/angular movement

    ********************************************"""







    """ ********************************************
    Do not edit code under this line
    ******************************************** """

  
if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass