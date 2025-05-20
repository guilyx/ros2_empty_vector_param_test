FROM ros:rolling

# Install dependencies
RUN apt-get update && apt-get install -y \
    python3-pip \
    python3-colcon-common-extensions \
    ros-$ROS_DISTRO-ament-cmake-google-benchmark \
    ros-$ROS_DISTRO-performance-test-fixture \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

# Create workspace directory
WORKDIR /ros2_ws

# Copy package files
COPY empty_vector_param_test /ros2_ws/src/empty_vector_param_test/
COPY rclcpp /ros2_ws/src/rclcpp/
COPY rcl_interfaces /ros2_ws/src/rcl_interfaces/
COPY test_interface_files /ros2_ws/src/test_interface_files/

# Build the package
RUN . /opt/ros/${ROS_DISTRO}/setup.sh && \
    colcon build --symlink-install

# Source setup file
RUN echo "source /opt/ros/${ROS_DISTRO}/setup.bash" >> ~/.bashrc && \
    echo "source /ros2_ws/install/setup.bash" >> ~/.bashrc

# Set the entrypoint
ENTRYPOINT ["/bin/bash", "-c", "source /opt/ros/${ROS_DISTRO}/setup.bash && source /ros2_ws/install/setup.bash && $0 $@"]