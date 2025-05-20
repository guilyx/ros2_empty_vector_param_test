# Why Support Empty Arrays as Parameter Values in ROS 2

## What is to be changed
- Add a new parameter type (PARAMETER_EMPTY_ARRAY) to rclcpp and rcl_interfaces to explicitly represent empty arrays/lists as parameter values.
- Update rclcpp, rcl, and message/service definitions to support this type in all parameter APIs, YAML files, and CLI tools.
- Ensure empty arrays are handled consistently, without ambiguity, across all interfaces.
- Implement type stability logic in rclcpp's node parameter setting (node_parameters.cpp):
  - If a parameter is set to an empty array and already has a concrete array type, keep the type and set the value to empty.
  - If the parameter is not set, allow PARAMETER_EMPTY_ARRAY as the type.

## Why change it
- Current ROS 2 behavior is inconsistent: empty lists are not always accepted or are misinterpreted (e.g., as boolean arrays).
- Users expect to specify empty arrays in YAML, CLI, and API, but this is not reliably supported.
- Making empty arrays a first-class parameter type improves consistency, predictability, and user experience in parameter handling.

## Approach
- Follow proposal by @nnmm in https://github.com/ros2/rclcpp/issues/1955
- Extend the parameter type enums in `rclcpp` and `rcl_interfaces` to include `PARAMETER_EMPTY_ARRAY`.
- Update `rclcpp::ParameterValue` and related APIs to recognize and handle the new type.
- Modify parameter parsing and serialization logic in `rclcpp`, `rcl`, and CLI tools to preserve empty arrays as their own type.
- Update message/service definitions (e.g., `ParameterType.msg`) to support the new type.
- Ensure that when a parameter is set to an empty array, its type is preserved if previously known, or set to `PARAMETER_EMPTY_ARRAY` if unknown.
- Add and update tests to verify correct handling and propagation of empty arrays in all supported interfaces.
