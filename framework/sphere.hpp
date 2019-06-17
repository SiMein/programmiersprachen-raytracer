#ifndef SPHERE_HPP
#define SPHERE_HPP

class Sphere : public Shape{
    public:
    Sphere(); // Default-constr.



    private: //  private auch bei ableitenden Klassen oder protected oder auch public ??
    glm::vec3 center_; 
    float radius_;
}

#endif // SPHERE_HPP