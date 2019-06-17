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
  return M_PI * radius_ * radius_;
}

float Sphere::volume() const override{  // Formel checken !!!
    return 1.0;
}

public:
    Sphere::Sphere(); // Defaul-constr., mit default-Werten