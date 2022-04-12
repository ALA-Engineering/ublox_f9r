#include <memory>

#include <diagnostic_updater/diagnostic_updater.hpp>
#include <rclcpp/rclcpp.hpp>

#include <ublox_gps/gnss.hpp>
#include <ublox_gps/ublox_firmware.hpp>


#include <sensor_msgs/msg/nav_sat_status.hpp>

#include <ublox_msgs/msg/cfg_gnss_block.hpp>
#include <ublox_msgs/msg/mon_hw.hpp>
#include <ublox_msgs/msg/nav_pvt.hpp>
#include <ublox_msgs/msg/nav_sat.hpp>
#include <ublox_msgs/msg/rxm_rtcm.hpp>


#include <ublox_gps/utils.hpp>

namespace ublox_node {

//
// U-Blox Firmware (all versions)
//
UbloxFirmware::UbloxFirmware(std::shared_ptr<diagnostic_updater::Updater> updater, std::shared_ptr<Gnss> gnss, rclcpp::Node* node) : updater_(updater), gnss_(gnss), node_(node)
{
}

void UbloxFirmware::initializeRosDiagnostics() {
  updater_->add("fix", this, &UbloxFirmware::fixDiagnostic);
  updater_->force_update();
}



}  // namespace ublox_node
