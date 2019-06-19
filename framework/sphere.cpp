#include "sphere.hpp"
#include <cmath>
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
  return 4*M_PI * pow(get_radius(), 2);
}

float Sphere::volume() const override{  // Formel checken !!!
    return (4.0f/3.0f)* M_PI * pow(get_radius(), 3);
}

public:
    Sphere::Sphere(); // Defaul-constr., mit default-Werten