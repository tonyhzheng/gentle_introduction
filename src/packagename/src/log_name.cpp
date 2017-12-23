#include <ros/ros.h>
#include <iostream>

int main(int argc, char **argv) {

	ros::init(argc,argv, "log_node_name");

	ros::NodeHandle nh;

	ros::Rate rate(10);

	for (int i=1; i<=20;i++){
		ROS_DEBUG_STREAM("ROS_DEBUG_STREAM: count= " << i);

		if((i%3) == 0){
			ROS_INFO_STREAM("ROS_INFO_STREAM:" << i << " is divisible by 3.");	
		}
		if((i%5) == 0){
			ROS_WARN_STREAM("ROS_WARN_STREAM:" << i << " is divisible by 5.");	
		}
		if((i%10) == 0){
			ROS_ERROR_STREAM("ROS_ERROR_STREAM:" << i << " is divisible by 10.");	
		}
		if((i%20) == 0){
			ROS_FATAL_STREAM("ROS_FATAL_STREAM:" << i << " is divisible by 20.");	
		}
		rate.sleep();
	}

	ROS_DEBUG("ROS_DEBUG: %0.2f",25.12345);
	ROS_INFO("ROS_INFO: %0.2f",25.12345);
	ROS_WARN("ROS_WARN: %0.2f",25.12345);
	ROS_ERROR("ROS_ERROR: %0.2f",25.12345);
	ROS_FATAL("ROS_FATAL: %0.2f",25.12345);

	for (int j=1;j<=20;j++){
		ROS_DEBUG_ONCE("ROS_DEBUG_ONCE: %0.2f",25.12345);
		ROS_INFO_ONCE("ROS_INFO_ONCE: %0.2f",25.12345);
		ROS_WARN_ONCE("ROS_WARN_ONCE: %0.2f",25.12345);
		ROS_ERROR_ONCE("ROS_ERROR_ONCE: %0.2f",25.12345);
		ROS_FATAL_ONCE("ROS_FATAL_ONCE: %0.2f",25.12345);
	}
 	
 	while(ros::ok()){ 
		ROS_DEBUG_STREAM_THROTTLE(0.5, "ROS_DEBUG_STREAM_THROTTLE: 0.5 seconds");
		ROS_INFO_STREAM_THROTTLE(1, "ROS_INFO_STREAM_THROTTLE: 1.0 seconds");
		ROS_WARN_STREAM_THROTTLE(1.5, "ROS_WARN_STREAM_THROTTLE: 1.5 seconds");
		ROS_ERROR_STREAM_THROTTLE(2, "ROS_ERROR_STREAM_THROTTLE: 2.0 seconds");
		ROS_FATAL_STREAM_THROTTLE(2.5, "ROS_FATAL_STREAM_THROTTLE: 2.5 seconds");

 	}
}
