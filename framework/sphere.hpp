#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

class Sphere : public Shape{
    public:
    Sphere(); // Default-constr.
    Sphere(glm::vec3 const& center, float radius);  // Custom-constr.

    /* virtual */float area() const override ;
    /* virtual */float volume () const override ;

    private: //  private auch bei ableitenden Klassen oder protected oder auch public ??
    glm::vec3 center_; 
    float radius_;
};

#endif // SPHERE_HPP