#include "box.hpp"
#include <glm/vec3.hpp>
#include <cmath>


Box::Box() :      // default-constr-Sphere
  Shape::Shape{"Box"},
  min_ {0.0f, 0.0f, 0.0f},
  max_ {1.0f, 1.0f,1.0}{}

Box::Box(glm::vec3 const& min,glm::vec3 const& max) :      // custom-constr-Sphere
  Shape::Shape{"Box"},
  min_ {min},
  max_ {max}{}


float Box::area() const {        // Formel checken !!!
  return abs(-1.0f);                  // abs-standarsfkt für betragsausgabe aus cmath librarys
}

float Box::volume() const {  // Formel checken !!!
    return abs(1.0f);
}

