cmake_minimum_required(VERSION 3.8)
project(bhf_vo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)  
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)

# Add executable
add_executable(bhf_vo_node src/bhf_vo_node.cpp)

# Include directories
target_include_directories(bhf_vo_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  ${OpenCV_INCLUDE_DIRS}
)

# Link against ROS2 and OpenCV libraries
ament_target_dependencies(bhf_vo_node rclcpp sensor_msgs geometry_msgs cv_bridge OpenCV)

# Set compile features
target_compile_features(bhf_vo_node PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

# Install the executable
install(TARGETS bhf_vo_node
  DESTINATION lib/${PROJECT_NAME}
)

# Testing
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

