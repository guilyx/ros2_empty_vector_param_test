#include <memory>
#include <vector>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class VectorParamNode : public rclcpp::Node
{
public:
    VectorParamNode() : Node("vector_param_node")
    {
        // Declare and get vector parameter
        this->declare_parameter("test_vector", std::vector<std::string>{});
        this->declare_parameter("test_param", "default_value");
        auto test_vector = this->get_parameter("test_vector").as_string_array();
        auto test_param = this->get_parameter("test_param").as_string();

        RCLCPP_INFO(this->get_logger(), "Vector parameter size: %zu", test_vector.size());

        // Print vector contents
        for (size_t i = 0; i < test_vector.size(); ++i) {
            RCLCPP_INFO(this->get_logger(), "Vector[%zu]: %s", i, test_vector[i].c_str());
        }

        RCLCPP_INFO(this->get_logger(), "Test param: %s", test_param.c_str());
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<VectorParamNode>());
    rclcpp::shutdown();
    return 0;
}