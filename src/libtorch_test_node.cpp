#include <torch/torch.h>
#include <iostream>
#include <ros/ros.h>
#include <torch/script.h>
#include <vector>

int main(int argc, char **argv) {
    
  ros::init(argc, argv, "libtorch_test");
  ros::NodeHandle nh_;
      
  torch::Tensor tensor = torch::rand({1, 3, 640, 640});
//   std::cout << tensor << std::endl;
  
  torch::jit::script::Module module;
  
  module = torch::jit::load("/home/anton/Projects/yolov7/runs/train/yolov7_gazebo_tiny_2/weights/best.torchscript.pt");
  
  std::cout << "Success load" << std::endl;
  
  std::vector<torch::jit::IValue> inputs;
  inputs.push_back(tensor);
  
  module.forward(inputs);
  
  std::cout << "FWD" << std::endl;
  
  
}
