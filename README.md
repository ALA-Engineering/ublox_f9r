# ublox_f9r

This repository contains packages for ublox f9r.


## Quick ROS2 Install

Instant install script for ROS2 on various versions of Ubuntu (20.04 LTS)Linux

### Install ROS2 on Ubuntu


put the ublox_f9r folder from the repo in the src folder of workspace

$ cd <ros_workspace>
$ colcon build
$ source install/setup.bash


# Open other terminal for ntrip client

    ROS node that will communicate with an NTRIP server to receive RTCM connections and publish them on a ROS topic.

    ros2 launch ntrip_client ntrip_client_launch.py


    Published Topics

    rtcm (mavros_msgs/RTCM)
    
    RTCM corrections received from NTRIP server. Only messages whose checksums have passed validation are sent. The messages contain the raw RTCM bytes including the checksum



```

## Bug Report

Prefer to open an issue. You can also send an E-mail to omprakashpatro@gmail.com.

