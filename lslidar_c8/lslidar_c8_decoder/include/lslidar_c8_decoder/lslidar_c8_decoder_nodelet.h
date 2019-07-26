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

#ifndef LSLIDAR_C8_DECODER_NODELET_H
#define LSLIDAR_C8_DECODER_NODELET_H

#include <ros/ros.h>
#include <pluginlib/class_list_macros.h>
#include <nodelet/nodelet.h>

#include <lslidar_c8_decoder/lslidar_c8_decoder.h>

namespace apollo {
namespace drivers {
namespace lslidar_c8_decoder {
class LslidarC8DecoderNodelet: public nodelet::Nodelet {
public:

  LslidarC8DecoderNodelet() {}
  ~LslidarC8DecoderNodelet() {}

private:

  virtual void onInit();
  LslidarC8DecoderPtr decoder;
};

} // end namespace lslidar_n301_decoder
}
}

#endif
