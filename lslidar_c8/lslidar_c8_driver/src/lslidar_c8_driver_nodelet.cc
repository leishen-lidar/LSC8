/***************************************************************************
Copyright 2018 The Leishen Authors. All Rights Reserved                     /
                                                                            /
Licensed under the Apache License, Version 2.0 (the "License");             /
you may not use this file except in compliance with the License.            /
You may obtain a copy of the License at                                     /
                                                                            /
    http://www.apache.org/licenses/LICENSE-2.0                              /
                                                                            /
Unless required by applicable law or agreed to in writing, software         /
distributed under the License is distributed on an "AS IS" BASIS,           /
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.    /
See the License for the specific language governing permissions and         /
limitations under the License.                                              /
****************************************************************************/

#include <string>
#include <boost/thread.hpp>

#include <ros/ros.h>
#include <pluginlib/class_list_macros.h>
#include <nodelet/nodelet.h>

#include <lslidar_c8_driver/lslidar_c8_driver_nodelet.h>

namespace apollo {
namespace drivers {
namespace lslidar_c8_driver
{

LslidarC8DriverNodelet::LslidarC8DriverNodelet():
  running(false) {
  return;
}

LslidarC8DriverNodelet::~LslidarC8DriverNodelet() {
  if (running) {
    NODELET_INFO("shutting down driver thread");
    running = false;
    device_thread->join();
    NODELET_INFO("driver thread stopped");
  }
  return;
}

void LslidarC8DriverNodelet::onInit()
{
  // start the driver
  lslidar_c8_driver.reset(
      new LslidarC8Driver(getNodeHandle(), getPrivateNodeHandle()));
  if (!lslidar_c8_driver->initialize()) {
    ROS_ERROR("Cannot initialize lslidar driver...");
    return;
  }

  // spawn device poll thread
  running = true;
  device_thread = boost::shared_ptr< boost::thread >
    (new boost::thread(boost::bind(&LslidarC8DriverNodelet::devicePoll, this)));
}

/** @brief Device poll thread main loop. */
void LslidarC8DriverNodelet::devicePoll()
{
  while(ros::ok()) {
    // poll device until end of file
    running = lslidar_c8_driver->polling();
    // ROS_INFO_THROTTLE(30, "polling data successfully");
    if (!running)
      break;
  }
  running = false;
}

} // namespace lslidar_driver
}
}
// Register this plugin with pluginlib.  Names must match nodelet_lslidar.xml.
//
// parameters are: package, class name, class type, base class type
PLUGINLIB_DECLARE_CLASS(lslidar_c8_driver, LslidarC8DriverNodelet,
                        apollo::drivers::lslidar_c8_driver::LslidarC8DriverNodelet, 
                        nodelet::Nodelet);
