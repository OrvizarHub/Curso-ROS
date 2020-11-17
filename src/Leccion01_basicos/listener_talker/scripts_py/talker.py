'''
File: /home/paultumbaco/catkin_ws/src/Curso-ROS/src/Leccion01_basicos/listener_talker/scripts_py/talker.py
Created Date: Monday November 16th 2020
Author: Paul Tumbaco
-----
Last Modified: Monday November 16th 2020 4:45:07 am
Modified By: the developer formerly known as Paul Tumbaco at <paultumbaco@gmail.com>
-----
Copyright (c) 2020 Orvizar
'''


#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String

def talker():
    #crea un nuevo publisher. especificamos el nombre del topico,
    #el tipo de mensage y el tamano
    pub = rospy.Publisher('chatter', String, queue_size=10)
    # Necesitamos inicializar el nodo
    # In ROS, nodes are uniquely named. If two nodes with the same
    # node are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'talker' node 
    rospy.init_node('talker', anonymous=True)
    #setear el loop rate
    rate = rospy.Rate(1) # 1hz
    #mantiene al nodo publicando hasta que Ctrl-C sea presionado
    i = 0
    while not rospy.is_shutdown():
        hello_str = "hello world %s" % i
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()
        i=i+1

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
