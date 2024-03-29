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

#include <lslidar_c8_driver/lslidar_c8_driver.h>
namespace apollo {
namespace drivers {
namespace lslidar_c8_driver
{

class LslidarC8DriverNodelet: public nodelet::Nodelet
{
public:

  LslidarC8DriverNodelet();
  ~LslidarC8DriverNodelet();

private:

  virtual void onInit(void);
  virtual void devicePoll(void);

  volatile bool running;               ///< device thread is running
  boost::shared_ptr<boost::thread> device_thread;

  LslidarC8DriverPtr lslidar_c8_driver; ///< driver implementation class
};

} // namespace lslidar_driver
}
}
