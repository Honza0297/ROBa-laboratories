# Setting up work with trilobot

Goal is to setup communication between PC and trilobot. ROS master will be running at PC.

## On trilobot:

Run Trilobot

On display run hotspot.sh and get-ip.sh. Script will open terminal and you will get \<trilo-IP>

## On PC:

Obtain \<PC-IP> by running command ifconfig. 

Set ROS_MASTER_URI=http://\<PC-IP>:11311

Set ROS_IP=\<PC-IP>

run roscore

## From PC connect to trilobot

ssh triloX@\<trilo-IP>

Set ROS_MASTER_URI=http://\<PC-IP>:11311/

Set ROS_IP=\<trilo-IP>

Run roslaunch trilobot rosserial.launch 

## Trilobot package

On pc needs to be built tribobot package that containst message types for communication with trilobot


## Check if everything works

On PC run rostopic echo /trolobot/sonar_data

You should be receiving data from trilobots sonars


# Running nodes in this exercise
Folders basic_subscriber and basic_publisher need to be copies to catkin_ws/src


On all *.py files needs to be run chmod +x *.py

run catkin_make


Every node in this exercise can be run by rosrun command, except exercise set to control trilobot with arrows. This node needs to be run by python3 (or from IDE by python3 equivalent)


