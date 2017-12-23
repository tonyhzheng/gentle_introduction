// Toggles between rotation and translation commands based on calls to a service
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_srvs/Empty.h>

bool forward = true;
bool toggleForward(
	std_srvs::Empty::Request &req,
	std_srvs::Empty::Response &resp
	){
	forward = !forward;
	ROS_INFO_STREAM("Now sending " << (forward ? "forward" : "rotate" ) << " commands.");
	return true;
}


int main(int argc, char **argv) {

	ros::init(argc,argv, "client_name");

	ros::NodeHandle nh;

	// Register service with master
	ros::ServiceServer servername = nh.advertiseService("toggle_forward", &toggleForward);

	//Publish commands using latest value for forward until node shuts down
	ros::Publisher pubname = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",1000);

	// Loop at 2Hz node shut down
	ros::Rate rate(2);
	
	while(ros::ok()){
		// Create and fill message
		// Other four fields ignored by turtlesim are default to 0
		geometry_msgs::Twist msg;
		msg.linear.x = forward ? 1.0 : 0.0;
		msg.angular.z = forward ? 0.0 : 1.0;


		// Publish message
		pubname.publish(msg);
		ros::spinOnce();
		/*
		ROS_INFO_STREAM("Sending this random velocity:"
			<<"linear:="<<msg.linear.x
			<< "angular=" <<msg.angular.z);
*/
		// Wait until it's time for another iteration
		rate.sleep();
	}

}
