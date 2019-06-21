#include "box.hpp"
#include <glm/vec3.hpp>
#include <cmath>
#include <iostream>


Box::Box() :      // default-constr-Sphere
  Shape::Shape{"Box"},
  min_ {0.0f, 0.0f, 0.0f},
  max_ {1.0f, 1.0f,1.0}{}

Box::Box(glm::vec3 const& min,glm::vec3 const& max) :      // custom-constr-Sphere
  Shape::Shape{"Box"},
  min_ {min},
  max_ {max}{}


float Box::area() const {        // Formel checken !!!
  if((min_.x > max_.x) || (min_.y > max_.y) || (min_.z > max_.z)){
    std::cout << "\nyour min and max values are incorrect !\n";
    return -1.0f;
  } 
  float x = max_.x - min_.x;
  float y = max_.y - min_.y;
  float z = max_.z - min_.z;
  
  return 2*(x*y + x*z + y*z);
}

float Box::volume() const {  // Formel checken !!!
  if((min_.x > max_.x) || (min_.y > max_.y) || (min_.z > max_.z)){
    std::cout << "\nyour min and max values are incorrect !\n";
    return -1.0f;
  } 
  float x = max_.x - min_.x;
  float y = max_.y - min_.y;
  float z = max_.z - min_.z;
  
  return (x*y*z);
}

