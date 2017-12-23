#include <ros/ros.h>
#include <std_srvs/Empty.h>

int main(int argc, char **argv) {

	ros::init(argc,argv, "set_background_color");

	ros::NodeHandle nh;

	// Wait until clear service is available, which indicates that turtlesim has started
	ros::service::waitForService("clear");

	//Set the background color
	ros::param::set("background_r", 255);
	ros::param::set("background_g", 255);
	ros::param::set("background_b", 0);

	// Get turtlesim to pick up the new parameter values
	ros::ServiceClient clearClient = nh.serviceClient<std_srvs::Empty>("/clear");
	std_srvs::Empty srv;
	clearClient.call(srv);

}