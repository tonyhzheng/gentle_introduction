#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	ros::init(argc,argv, "publish_velocity");

	ros::NodeHandle nh;

	// Create publisher object
	ros::Publisher pubname = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",1000);

	// Seed random number generator
	srand(time(0));

	// Loop at 2Hz node shut down
	ros::Rate rate(2);
	ros::param::set("/publish_velocity/max_vel",0.1);
	
	while(ros::ok()){
		// Create and fill message
		// Other four fields ignored by turtlesim are default to 0
		geometry_msgs::Twist msg;
		msg.linear.x = double(rand())/double(RAND_MAX);
		msg.angular.z = 2*double(rand())/double(RAND_MAX)-1;

		// Publish message
		pubname.publish(msg);

		ROS_INFO_STREAM("Sending this random velocity:"
			<<"linear:="<<msg.linear.x
			<< "angular=" <<msg.angular.z);

		// Wait until it's time for another iteration
		rate.sleep();
	}

}
