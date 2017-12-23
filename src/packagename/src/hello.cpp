#include <ros/ros.h>

int main(int argc, char **argv) {

	ros::init(argc,argv, "node_name_string");

	ros::NodeHandle nh;

	ROS_INFO_STREAM("HEEEEELLLO WOOOOOORLD");
}