FROM ros:humble

# Install dependencies
RUN apt-get update && apt-get install -y \
    python3-pip \
    python3-colcon-common-extensions \
    && rm -rf /var/lib/apt/lists/*

# Create workspace directory
WORKDIR /ros2_ws

# Copy package files
COPY empty_vector_param_test /ros2_ws/src/empty_vector_param_test/

# Build the package
RUN . /opt/ros/humble/setup.sh && \
    colcon build --symlink-install

# Source setup file
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc && \
    echo "source /ros2_ws/install/setup.bash" >> ~/.bashrc

# Set the entrypoint
ENTRYPOINT ["/bin/bash", "-c", "source /opt/ros/humble/setup.bash && source /ros2_ws/install/setup.bash && $0 $@"]