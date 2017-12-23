// This program spawns a new turtlesim turtle by calling the appropriate service

#include <ros/ros.h>
#include <turtlesim/Spawn.h>
#include <math.h>

int main(int argc, char **argv) {

	ros::init(argc,argv, "spawn_turtle");

	ros::NodeHandle nh;

	// Create client object for spawn service.
	// Needs to know the data type of the service and its name
	ros::ServiceClient spawnClient = nh.serviceClient<turtlesim::Spawn>("spawn");

	// Create the request object
	turtlesim::Spawn::Request req;

	// Create the response object
	turtlesim::Spawn::Response resp;

	// Fill in the request data members
	req.x = 2;
	req.y = 3;
	req.theta = 3.14/2;
	req.name = "Leo";

	//Actually call the service. Doesn't return until service completed
	bool success = spawnClient.call(req,resp);

	//Check for success and use response
	if (success) {
		ROS_INFO_STREAM("Spawned a turtle named " << resp.name);
	}
	else{
		ROS_ERROR_STREAM("Failed to spawn.");
	}
}