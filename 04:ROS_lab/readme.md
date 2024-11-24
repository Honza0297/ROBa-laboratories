# What needs to be done before running nodes

Folders basic_subscriber and basic_publisher need to be copies to catkin_ws/src


On all *.py files needs to be run chmod +x *.py

run catkin_make

## Following needs to be set

ROS_MAASTER_URI=http://localhost:11311   (otherwise roscore wont run)

unset ROS_IP

Sample code that should be able to run by now:

rosrun basic_publisher publisher_solved.py


# Making single shared ROS master

For advanced exercises there needs to be only one ROS master running (in order to have share chatter)

Choose single PC where ROS master will be running.

Take a look at the ROS_MASTER_URI when running roscore command

On other PCs do not run roscore, but change ROS_MASTER_URI to one, where ros master is running

Now it is possible to run ros nodes that communicate with shared ROS master

