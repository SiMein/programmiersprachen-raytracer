#include "box.hpp"
#include <glm/vec3.hpp>

Box::Box() :      // default-constr-Sphere
  Shape::Shape{"Box"},
  min_ {0.0f, 0.0f},
  max_ {5.0f, 5.0}{}

Box::Box(glm::vec3 const& min,glm::vec3 const& max) :      // custom-constr-Sphere
  Shape::Shape{"Box"},
  min_ {min},
  max_ {max}{}


float Box::area() const {        // Formel checken !!!
  return M_PI * radius_ * radius_;
}

float Box::volume() const override{  // Formel checken !!!
    return 1.0;
}

public:
    Box::Box(); // Defaul-constr., mit default-Werten