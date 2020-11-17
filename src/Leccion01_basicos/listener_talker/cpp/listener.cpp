/*
 * File: /home/paultumbaco/catkin_ws/src/Curso-ROS/src/Leccion01_basicos/listener_talker/cpp/listener.cpp
 * Created Date: Monday November 16th 2020
 * Author: Paul Tumbaco
 * -----
 * Last Modified: Monday November 16th 2020 4:45:25 am
 * Modified By: the developer formerly known as Paul Tumbaco at <paultumbaco@gmail.com>
 * -----
 * Copyright (c) 2020 Orvizar
 */


#include "ros/ros.h"
#include "std_msgs/String.h"

// Topic messages callback 
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("[Listener] I heard: [%s]\n", msg->data.c_str());
}

int main(int argc, char **argv)
{
    // Inicializa un nuevo nodo de ROS llamado "listener"
	ros::init(argc, argv, "listener_node");
	//crea un node handle: es una referencia asignada a un nuevo nodo
	ros::NodeHandle node;


    // Subscribe a un topico dado, in este caso "chatter".
	//chatterCallback: es el nombre de la callback function que va a ser ejecutada cada vez que un mensaje es recivido

    ros::Subscriber sub = node.subscribe("chatter", 1000, chatterCallback);

    // Entra al loop, llamando   callbacks
    ros::spin();

    return 0;
}
