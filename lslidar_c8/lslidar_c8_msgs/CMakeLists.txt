cmake_minimum_required(VERSION 2.8.3)
project(lslidar_c8_msgs)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  std_msgs
  sensor_msgs
)

add_message_files(
  DIRECTORY msg
  FILES
  LslidarC8Layer.msg
  LslidarC8Packet.msg
  LslidarC8Point.msg
  LslidarC8Scan.msg
  LslidarC8Sweep.msg
  LslidarC8ScanUnified.msg
)
generate_messages(DEPENDENCIES std_msgs sensor_msgs)

catkin_package(
  CATKIN_DEPENDS message_runtime std_msgs sensor_msgs
)
