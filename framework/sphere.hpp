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
    Sphere(glm::vec3 const& center,float radius,std::string name, std::shared_ptr<Material> const& ma_co); // Custom-constr-  4 param
    ~Sphere();


    /* virtual */ float area() const override;
    /* virtual */ float volume() const override;
    /* virtual */ HitPoint intersect(Ray const& ray) const override;
    /* virtual */ std::ostream& print(std::ostream& os) const override;
    
    private: //  private auch bei ableitenden Klassen oder protected oder auch public ??
    glm::vec3 center_; 
    float radius_;
};

#endif // SPHERE_HPP