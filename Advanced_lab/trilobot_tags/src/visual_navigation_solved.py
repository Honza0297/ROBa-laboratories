# Author: Jan Beran
# Last edit: 12122023
# Licence: Beerware; basically freeware, but if you meet me, you can buy me a beer :)
# University: FIT, BUT, Brno, Czech republic
import rospy
from trilobot.msg import Sonar_data
from geometry_msgs.msg import Twist, PoseWithCovarianceStamped, PoseWithCovariance, Pose, Point
from apriltag_ros.msg import AprilTagDetectionArray, AprilTagDetection


obstacle_present = False
tag_present = False

front_distance = 45 # init value
obstacle_distance_limit = 40

last_delta_x = 0
last_delta_y = 0

def sonar_callback(sonar_msg: Sonar_data):
    front_distance = sonar_msg.front
    if front_distance < obstacle_distance_limit:
        obstacle_present = True
    else:
        obstacle_present = False

    #rospy.loginfo("Front sonar distance:{}".format(sonar_msgc.front))



def tag_callback(msg: AprilTagDetectionArray):
    tag = msg.detections[0] if msg.detections else None

    if not tag:
        tag_present = False
    else:
        tag_present = True
        # This abomination below is caused by heavy nesting of several Pose message types.
        # Observe the http://docs.ros.org/en/kinetic/api/apriltag_ros/html/msg/AprilTagDetectionArray.html message signature to find out more! :)
        position = tag.pose.pose.pose.position
        rospy.loginfo("Tag position: {}".format(position))



def main():
    global forced_stop
    sonar_subscriber = rospy.Subscriber("/trilobot/sonar_data", Sonar_data, sonar_callback)
    apriltag_subscriber = rospy.Subscriber("/tag_detections", AprilTagDetectionArray, tag_callback)
    motor_publisher = rospy.Publisher("/cmd_vel", Twist, queue_size=500)
    while not rospy.is_shutdown():
        msg = Twist()
        if forced_stop:
            rospy.loginfo("Found obstacle")

                # Stop the robot
            msg.linear.x = 0
            msg.angular.z = 0
        
         # Publish the message
        pub.publish(msg)
        # Sleep for given time
        rospy.sleep(0.05)

if __name__ == "__main__":
    try:
        main()
    except rospy.ROSInterruptException:
        pass