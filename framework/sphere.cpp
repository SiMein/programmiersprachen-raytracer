#include "sphere.hpp"
#include <glm/vec3.hpp>

Sphere::Sphere() :      // default-constr-Sphere
  Shape::Shape{"Sphere"},
  center_     {0.0f, 0.0f, 0.0f},
  radius_     {1.0f}{}

Sphere::Sphere(glm::vec3 const& center, float radius) :      // custom-constr-Sphere
  Shape::Shape{"Sphere"},
  center_ {center},
  radius_ {radius}{}


float Sphere::area() const {        // Formel checken !!!
  return 4*M_PI * std::pow(radius_, 2);
}

float Sphere::volume() const{  // Formel checken !!!
    return (4.0f/3.0f)* M_PI * std::pow(radius_, 3);
}
