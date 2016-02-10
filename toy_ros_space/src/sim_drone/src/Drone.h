#ifndef CLASS_DRONE_H
#define CLASS_DRONE_H

#pragma once
#include <Eigen/Core>
#include <Eigen/Dense>
#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include "Quadrotor.h"

class Drone
{
	private:
		Quadrotor quad;

		/* target variables */
		/* first we only deal with attitude and height control */
		double ctrl_target_height;
		double ctrl_target_vertical_z;
		Eigen::Quaterniond target_attitude;

		/* some parameters */
		double gravity;
		double angle_limit;
		

		double height_ctrl(double target_vertical_pos_z, double target_vertical_vel_z, double pos_z, double vel_z);
		void attitude_ctrl(Eigen::Quaterniond target_attitude, double des_force_z);
	public:
		Drone();
		void sim_step(double dt);
		void obtain_joy(const sensor_msgs::Joy::ConstPtr& joy_msg);
		Eigen::Quaterniond get_attitude();
		Eigen::Vector3d get_position();

		
		
};

#endif