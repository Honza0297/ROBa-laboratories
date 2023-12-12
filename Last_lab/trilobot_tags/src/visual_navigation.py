#!/usr/bin/env python3

# Author: Jan Beran
# Last edit: 12122023
# Licence: Beerware; basically freeware, but if you meet me, you can buy me a beer :)
# University: FIT, BUT, Brno, Czech republic
import rospy
from trilobot.msg import Sonar_data
from geometry_msgs.msg import Twist, PoseWithCovarianceStamped, PoseWithCovariance, Pose, Point
from apriltag_ros.msg import AprilTagDetectionArray, AprilTagDetection
from math import sqrt, atan2

obstacle_present = False
tag_present = False

front_distance = 45 # init value
obstacle_distance_limit = 40

robot_tag_distance = 0
tag_sideway_position = 0

angular_coeff = 1

def sonar_callback(sonar_msg: Sonar_data):
    global front_distance
    global obstacle_present
    front_distance = sonar_msg.front
    if front_distance < obstacle_distance_limit:
        obstacle_present = True
    else:
        obstacle_present = False


def tag_callback(msg: AprilTagDetectionArray):
    global tag_present
    global robot_tag_distance
    global tag_sideway_position
    tag = msg.detections[0] if msg.detections else None

    if not tag:
        tag_present = False
    else:
        tag_present = True
        # This abomination below is caused by heavy nesting of several Pose message types.
        # Observe the http://docs.ros.org/en/kinetic/api/apriltag_ros/html/msg/AprilTagDetectionArray.html message signature to find out more! :)
        position = tag.pose.pose.pose.position
        
        robot_tag_distance = position.z
        # negative = tag is to the left, positive = tag is to the right, relative to the robot/camera
        tag_sideway_position = position.x
        rospy.loginfo(position)
        #rospy.loginfo("Tag position: {}".format(position))

tag_sideway_position

def main():
    global obstacle_present
    global tag_present
    rospy.init_node("trilobot_tag_navigator")
    sonar_subscriber = rospy.Subscriber("/trilobot/sonar_data", Sonar_data, sonar_callback)
    apriltag_subscriber = rospy.Subscriber("/tag_detections", AprilTagDetectionArray, tag_callback)
    motor_publisher = rospy.Publisher("/cmd_vel", Twist, queue_size=500)

    while not rospy.is_shutdown():
        msg = Twist()
        msg.linear.x = 0
        msg.angular.z = 0
        if obstacle_present:
            rospy.loginfo("Found obstacle")
            # Stop the robot
            msg.linear.x = 0
            msg.angular.z = 0
        elif not tag_present:
            rospy.loginfo("No tag to follow")
            # Stop the robot
            msg.linear.x = 0
            msg.angular.z = 0
        else:
            """
            Your task is to follow the Apriltag in the room. 

            The position of the Apriltag (relative to the robot) is expressed as:
            * distance in x direction (in front of robot): robot_tag_distance [m]
            * how much to the side the tag is: tag_sideway_position [m]

            More specifically, you need to find linear and angular velocity for the robot to follow the tag.

            HINT #1: start with printing (either with print or rospy.loginfo) the values to get familiar with them. Observe when the values is bigger/smaller, positive, negative...

            Next hints will be revelaed during the exercise :) 
            """
            # you can delete the keyword "pass" once you get something in the "else:"" branch
            pass
         # Publish the message
        motor_publisher.publish(msg)
        # Sleep for given time
        rospy.sleep(0.05)

if __name__ == "__main__":
    try:
        main()
    except rospy.ROSInterruptException:
        pass