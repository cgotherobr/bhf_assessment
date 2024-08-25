# Use ROS2 Humble as the base image
FROM osrf/ros:humble-desktop

# Install additional dependencies
RUN apt-get update && \
    apt-get install -y \
    python3-colcon-common-extensions \
    build-essential \
    cmake \
    git \
    libopencv-dev \
    ros-humble-cv-bridge \
    ros-humble-image-transport \
    ros-humble-rclcpp \
    ros-humble-sensor-msgs \
    ros-humble-geometry-msgs \
    ros-humble-std-msgs && \
    rm -rf /var/lib/apt/lists/*

# Set the working directory inside the container
WORKDIR /bhf_assessments

# Copy the source code into the container
COPY ./src ./src

# Copy the entrypoint script into the container
COPY docker/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

# Set the entrypoint
ENTRYPOINT ["/entrypoint.sh"]

# Default command (can be overridden)
CMD ["ros2", "run", "bhf_vo", "visual_odometry_node"]

