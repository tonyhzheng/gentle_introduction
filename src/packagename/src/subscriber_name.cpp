#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <iomanip> //for std::setprecision and std::fixed

// A callback function
// Executed each time a new pose message arrives

void poseMessageReceivedCallback(const turtlesim::Pose& msg){

	ROS_INFO_STREAM(std::setprecision(2) << std::fixed
			<<"position="<< msg.x << "," << msg.y << ")\n"
			<< "direction=" << msg.theta);


}

int main(int argc, char **argv) {

	ros::init(argc,argv, "subscribe_to_pose");
	ros::NodeHandle nh;

	// Create Subscriber object
	ros::Subscriber subname = nh.subscribe("turtle1/pose", 1000, &poseMessageReceivedCallback);

	// Let ROS take over
	ros::spin();

}
