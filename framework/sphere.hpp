#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>
#include "hitPoint.hpp"
#include "ray.hpp"
#include <glm/gtx/intersect.hpp>

class Sphere : public Shape{
    public:
    Sphere(); // Default-constr.
    Sphere(glm::vec3 const& center, float radius);  // Custom-constr. 2 param
    Sphere(glm::vec3 const& center,float radius,std::string name,Color color); // Custom-constr-  4 param
    ~Sphere();

    /* virtual */float area() const override;
    /* virtual */float volume() const override;
    /* virtual */std::ostream& print(std::ostream& os) const override;
    HitPoint intersect(Ray const& r) const;

    private: //  private auch bei ableitenden Klassen oder protected oder auch public ??
    glm::vec3 center_; 
    float radius_;
};

#endif // SPHERE_HPP