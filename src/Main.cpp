/*
 * Copyright (c) 2013, Fraunhofer FKIE
 *
 * Authors: Bastian Gaspers
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * * Neither the name of the Fraunhofer FKIE nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * This file is part of the StructureColoring ROS package.
 *
 * The StructureColoring ROS package is free software:
 * you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The StructureColoring ROS package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with The StructureColoring ROS package.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include <structureColoring/StructureColoring.h>
#include <ros/ros.h>

int main(int argc, char* argv[]) {
	ros::init(argc, argv, "structureColoring");
	ros::Time::init();
	ros::Rate loop_rate(10);
	ros::NodeHandle n;
	StructureColoring structureColoring(n, argc, argv);
	if (structureColoring.waitOnKinectMsgs() || structureColoring.waitOnLaserMsgs())
		while (n.ok()) {
			ros::spinOnce();
			//structureColoring.update();
			loop_rate.sleep();
		}
	else
		structureColoring.getPointsFromFile();
    ros::spinOnce();
    usleep(300000);
	return 0;
}
