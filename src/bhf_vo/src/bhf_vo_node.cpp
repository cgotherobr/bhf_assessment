#include <cstdio>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
using std::placeholders::_1;
class VisualOdometryNode : public rclcpp::Node {
public:
    VisualOdometryNode() : Node("visual_odometry_node") {
        // Set up subscriber for the image input topic
        image_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
            "camera/image_raw/compressed", 10,
            std::bind(&VisualOdometryNode::imageCallback, this, _1)
        );
        // Set up publiser for the VO info
        VO_publisher_ = this->create_publisher<std_msgs::msg::String>("VO", 10);
        
        

    
 int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<VisualOdometryNode>());
  rclcpp::shutdown();
  return 0;
}
