cmake_minimum_required(VERSION 2.8.3)
project(curso_ros)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)


## Generate messages in the 'msg' folder
 ##add_message_files(


##)

## Generate services in the 'srv' folder
 ##add_service_files(
 ##  FILES 

 ##  )

## Generate actions in the 'action' folder
##add_action_files(

##)

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
 )


###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES curso_ros
  CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
 
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}

)



#talker
add_executable(talker_nodo src/Leccion01_basicos/listener_talker/cpp/talker.cpp)
target_link_libraries (talker_nodo ${catkin_LIBRARIES})
#add_dependencies(talker gaitech_doc_generate_message_cpp)

#listener
add_executable(listener_nodo src/Leccion01_basicos/listener_talker/cpp/listener.cpp)
target_link_libraries (listener_nodo ${catkin_LIBRARIES})


catkin_install_python(PROGRAMS src/Leccion01_basicos/listener_talker/scripts/talker.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
catkin_install_python(PROGRAMS src/Leccion01_basicos/listener_talker/scripts/listener.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)