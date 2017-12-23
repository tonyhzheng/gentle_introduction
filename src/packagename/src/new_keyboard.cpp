// This program subscribes to turtle1/cmd_vel and republished on "turtle1/cmd_vel_reversed" topic with signs inverted

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <barc/ECU.h>
#include <math.h>
#include <stdio.h>


ros::Publisher *pubPtr;
barc::ECU msgOut;

void commandVelocityReceived(const geometry_msgs::Twist& msgIn){

	msgOut.motor = round((msgOut.motor+msgIn.linear.x*0.01)*10000)/10000;
	/*if (msgOut.motor <0){
		msgOut.motor  = 0;
	}*/
	msgOut.servo = round((msgOut.servo+msgIn.angular.z*0.01)*10000)/10000;
	pubPtr->publish(msgOut);
}

int main(int argc, char **argv) {

	ros::init(argc,argv, "reverse_velocity_node");

	ros::NodeHandle nh;
	pubPtr = new ros::Publisher(nh.advertise<barc::ECU>("/ecu",1000));

	ros::Subscriber sub = nh.subscribe("turtle1/cmd_vel",1000,&commandVelocityReceived);

	ros::spin();

	delete pubPtr;

	}