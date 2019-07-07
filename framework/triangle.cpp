#include "triangle.hpp"
#include <glm/vec3.hpp>
#include <cmath>
#include <iostream>


Triangle::Triangle() :      // default-constr-Sphere
  Shape::Shape{"Triangle"},    // hier uebertragung des Strings "Box" in die Basisklasse als name-parameter
  e1_ {0.0f, 0.0f, 0.0f},
  e2_ {0.0f, 5.0f, 0.0f},
  e3_ {0.0f, 0.0f, 5.0f}{/* std::cout << "I am the Triangle-contructor !";*/}
/* 
Triangle::Triangle(glm::vec3 const& min,glm::vec3 const& max) :   // custom-constr-Sphere 2 param
  Shape::Shape{"Triangle"},
  min_ {min},
  max_ {max}{/* std::cout << "I am the Triangle-contructor !";*/ //}
/*
Triangle::Triangle(glm::vec3 const& min,glm::vec3 const& max,std::string name,Color color) :  // custom-constr-Sphere 4 param
  Shape::Shape{name,color},  // Parameter werden weitergereicht an den konstr der basisklasse für die entspr. parameter
  min_ {min},
  max_ {max}{/* std::cout << "I am the Triangle-contructor !";*/ //}

Triangle::~Triangle(){
  //std::cout << "I am the Triangle-Destruktor !";
}


float Triangle::area() const {        // Formel checken !!!
  //if((min_.x > max_.x) || (min_.y > max_.y) || (min_.z > max_.z)){
  //  std::cout << "\nyour min and max values are incorrect !\n";
    return -1.0f;
}

float Triangle::volume() const {  // Formel checken !!!
  //if((min_.x > max_.x) || (min_.y > max_.y) || (min_.z > max_.z)){
  //  std::cout << "\nyour min and max values are incorrect !\n";
    return -1.0f;
}


std::ostream& Triangle::print(std::ostream& os) const {
  Shape::print(os); // print methode der basisklasse wir mit augerufen -für basis attributausgabe
  /* os << "Minimum : " << min_.x << "\t" << min_.y << "\t" << min_.z << "\n"
     << "Maximum : " << max_.x << "\t" << max_.y << "\t" << max_.z << "\n";*/
}

