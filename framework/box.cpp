#include "box.hpp"
#include <glm/vec3.hpp>
#include <cmath>
#include <iostream>


Box::Box() :      // default-constr-Sphere
  Shape::Shape{"Box"},    // hier uebertragung des Strings "Box" in die Basisklasse als name-parameter
  min_ {0.0f, 0.0f, 0.0f},
  max_ {1.0f, 1.0f,1.0}{std::cout << "I am the Box-contructor !";}

Box::Box(glm::vec3 const& min,glm::vec3 const& max) :   // custom-constr-Sphere 2 param
  Shape::Shape{"Box"},
  min_ {min},
  max_ {max}{std::cout << "I am the Box-contructor !";}

Box::Box(glm::vec3 const& min,glm::vec3 const& max,std::string name,Color color) :  // custom-constr-Sphere 4 param
  Shape::Shape{name,color},  // Parameter werden weitergereicht an den konstr der basisklasse für die entspr. parameter
  min_ {min},
  max_ {max}{std::cout << "I am the Box-contructor !";}

Box::~Box(){
  std::cout << "I am the Box-Destruktor !";
}


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

std::ostream& Box::print(std::ostream& os) const {
  Shape::print(os); // print methode der basisklasse wir mit augerufen -für basis attributausgabe
  os << "Minimum : " << min_.x << "\t" << min_.y << "\t" << min_.z << "\n"
     << "Maximum : " << max_.x << "\t" << max_.y << "\t" << max_.z << "\n";
}

