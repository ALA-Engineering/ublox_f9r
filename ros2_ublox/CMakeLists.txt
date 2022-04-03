cmake_minimum_required(VERSION 3.5)
project(ros2_ublox)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(ublox_msgs REQUIRED)
find_package(jsoncpp REQUIRED)

include_directories(
  include
)

# Create separate executables for the default and Tins drivers.
set(executable_name ublox_driver)
set(tins_executable_name ublox_tins_driver)

# Create a single library target to use for both default and Tins driver.
set(library_name ${executable_name}_core)

set(dependencies
  rclcpp
  rclcpp_lifecycle
  rclcpp_components
  sensor_msgs
  std_msgs
  std_srvs
  geometry_msgs
  builtin_interfaces
  tf2_ros
  ublox_msgs
  tf2_geometry_msgs
)

add_library(${library_name} SHARED

)

ament_target_dependencies(${library_name}
  ${dependencies}
)


add_executable(${executable_name}
  src/main.cpp
)


target_link_libraries(${executable_name} ${library_name})


rclcpp_components_register_nodes(${library_name} "${PROJECT_NAME}::Driver")

set(node_plugins "${node_plugins}${PROJECT_NAME}::Driver;$<TARGET_FILE:ublox_driver>\n")
set(node_plugins "${node_plugins}${PROJECT_NAME}::TinsDriver;$<TARGET_FILE:ublox_driver>\n")

install(TARGETS ${executable_name} ${tins_executable_name} ${library_name}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include/
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY params
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(include)
ament_export_libraries(${library_name})
ament_export_dependencies(${dependencies})
ament_package()