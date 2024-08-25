#!/bin/bash
set -e

# Source the ROS2 setup script
source /opt/ros/humble/setup.bash

# Source the workspace setup script if it exists
if [ -f "/bhf_assessments/install/setup.bash" ]; then
    source /bhf_assessments/install/setup.bash
else
    # Build the workspace if setup.bash doesn't exist
    cd /bhf_assessments
    colcon build
    source /bhf_assessments/install/setup.bash
fi

# Execute the passed command
exec "$@"

