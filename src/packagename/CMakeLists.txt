cmake_minimum_required(VERSION 2.8.3)
project(packagename)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS roscpp geometry_msgs turtlesim barc)

## Generate messages in the 'msg' folder
 add_message_files(
   FILES
   new_message.msg
   the_office_crew.msg
 )

## Generate added messages and services with any dependencies listed here
generate_messages(
   DEPENDENCIES
   std_msgs  # Or other packages containing msgs
 )

# Declare our catkin package
catkin_package()

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
	${catkin_INCLUDE_DIRS}
)

# Declare executable along with source files
add_executable(hello_executable src/helloworld.cpp)
add_executable(publisher_executable src/publisher_name.cpp)
add_executable(subscriber_executable src/subscriber_name.cpp)
add_executable(log_executable src/log_name.cpp)
add_executable(reverse_vel_cmd_executable src/reverse_cmd_vel.cpp)
add_executable(publish_velocity_executable src/publish_velocity_with_max.cpp)
add_executable(set_background_color_executable src/set_background_color.cpp)
add_executable(client_name_executable src/client_name.cpp)
add_executable(server_name_executable src/server_name.cpp)
add_executable(new_keyboard_executable src/new_keyboard.cpp)

# Specify libraries against which to link
target_link_libraries(hello_executable ${catkin_LIBRARIES})
target_link_libraries(publisher_executable ${catkin_LIBRARIES})
target_link_libraries(subscriber_executable ${catkin_LIBRARIES})
target_link_libraries(log_executable ${catkin_LIBRARIES})
target_link_libraries(reverse_vel_cmd_executable ${catkin_LIBRARIES})
target_link_libraries(publish_velocity_executable ${catkin_LIBRARIES})
target_link_libraries(set_background_color_executable ${catkin_LIBRARIES})
target_link_libraries(client_name_executable ${catkin_LIBRARIES})
target_link_libraries(server_name_executable ${catkin_LIBRARIES})
target_link_libraries(new_keyboard_executable ${catkin_LIBRARIES})