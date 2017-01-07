#include "ros/ros.h"
#include "geometry_msgs/Twist.h" 

int main(int argc, char **argv)
{
	srand(time(NULL));
	ros::init(argc, argv, "lab1");
	ros::NodeHandle node;
	ros::Publisher pub = node.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
	ros::Rate loopRate(100);

	while(ros::ok()) {
		geometry_msgs::Twist msg;

		msg.angular.z = (double)(rand() % 5 + 1);
		msg.linear.x = (double)(rand() % 5 + 1);

		pub.publish(msg);

		ros::spinOnce();
		loopRate.sleep();
	}

	return 0;
}
