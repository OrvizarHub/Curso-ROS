/*
 * File: /home/paultumbaco/catkin_ws/src/Curso-ROS/src/Leccion01_basicos/listener_talker/cpp/talker.cpp
 * Created Date: Monday November 16th 2020
 * Author: Paul Tumbaco
 * -----
 * Last Modified: Monday November 16th 2020 4:45:34 am
 * Modified By: the developer formerly known as Paul Tumbaco at <paultumbaco@gmail.com>
 * -----
 * Copyright (c) 2020 Orvizar
 */



#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{
	// Inicializa in nuevo Nodo llamado "talker"
	ros::init(argc, argv, "talker_node");

	//crea un node handle: es una referencia asignada a un nuevo nodo
	ros::NodeHandle n;
	//crea un publisher con un topico llamado "chatter" que enviara un mensaje tipo  String 
	ros::Publisher chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
	//Rate es una clase  que es usafa para definir la frecuencia de un loop. Aqui vamos a enviar un mensaje
    // cada 2 segundos
	ros::Rate loop_rate(0.5); //1 message per second

   int count = 0;
   while (ros::ok()) //va a seguir en el loop spinning hasta que presionemos Ctrl+C
   {
       //crea un nuevo mensaje ROS tipo string.
	   //Message definition in this link http://docs.ros.org/api/std_msgs/html/msg/String.html
	   std_msgs::String msg;

       //crear un string para los datos
	   std::stringstream ss;
	   ss << "Hello World " << count;
	   //asignar el dato al mensage , recuerda el tipo del dato es string, por ende necesita convesion
       msg.data = ss.str();

       //imprime el contenido en la consola, el contenido del mensaje
       ROS_INFO("[Talker] I published %s\n", msg.data.c_str());

       //Publish (publica el mensaje)
       chatter_publisher.publish(msg);

       ros::spinOnce(); // NECESARIO llamar a esta funcion frecuentemente para que ROS procese los mensajes

      loop_rate.sleep(); // Sleep  en el resto del ciclo  , de este manera se  cumple el bucle
      
       count++;
   }
   return 0;
}


