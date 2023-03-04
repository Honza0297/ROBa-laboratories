# DO NOT skip the next commented line
#!/usr/bin/env python
  
import rospy
from std_msgs.msg import String
from trilobot.msg import Sonar_data
from geometry_msgs.msg import Twist

distance = 0.0
messages_num = 20
mode = "forward"
  
def callback(data:Sonar_data):
    global distance 
    # print the actual message in its raw format
    print(data)
    distance = data.front
    #rospy.loginfo("Here's what was subscribed: %s", data.data)
      
    # otherwise simply print a convenient message on the terminal
    print('Data from /topic_name received')
  
  
def main():
    global mode
    #global distance
    pub = rospy.Publisher('/cmd_vel', Twist, queue_size=500)

    # initialize a node by the name 'listener'.
    # you may choose to name it however you like,
    # since you don't have to use it ahead
    rospy.init_node('betar', anonymous=True)
    rospy.Subscriber("/trilobot/sonar_data", Sonar_data, callback)


			
		#print(datetime.datetime.now())
      
    # spin() simply keeps python from
    # exiting until this node is stopped
    while not rospy.is_shutdown():
        message = Twist()
        print(mode)
        
        if mode == "forward":
            print(1)
            message.angular.z= 0

            if distance < 40:   
                message.linear.x = 0
                messages_sent = 0
                mode = "rotate"
            else:
                message.linear.x = distance/300
            print(message.linear.x)

        elif mode == "rotate":
            print(2)
            message.linear.x = 0

            message.angular.z = 1

            messages_sent += 1 
            if messages_sent >= messages_num:
                mode = "forward"
        print(message)
        # do whatever you want here
        pub.publish(message)
        rospy.sleep(0.05)  # sleep for one second

  
if __name__ == '__main__':
      
    # you could name this function
    try:
        main()
    except rospy.ROSInterruptException:
        pass