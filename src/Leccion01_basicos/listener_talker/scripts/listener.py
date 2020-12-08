'''
File: /home/paultumbaco/catkin_ws/src/Curso-ROS/src/Leccion01_basicos/listener_talker/scripts_py/listener.py
Created Date: Monday November 16th 2020
Author: Paul Tumbaco
-----
Last Modified: Monday November 16th 2020 4:44:53 am
Modified By: the developer formerly known as Paul Tumbaco at <paultumbaco@gmail.com>
-----
Copyright (c) 2020 Orvizar
'''

#!/usr/bin/env python
import rospy
from std_msgs.msg import String

def chatter_callback(message):
    #get_caller_id():  Recibe el nombre del nodo local completo 
    #rospy.loginfo(rospy.get_caller_id() + "   Escucho este dato  %s", message.data)
    print("   Hola: %s", message.data)
    
def listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # node are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.

    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber("nombre", String, chatter_callback)

    # spin() evita que python termine el programa hasta que el nodo sea detenido
    
    rospy.spin()

if __name__ == '__main__':
    listener()
