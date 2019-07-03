#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

class Triangle : public Shape { // abgeleitete Klasse und ableitende Klasse
    
    public:
    Triangle(); // Defaul-constr., mit default-Werten
    //Triangle(glm::vec3 const& min_,glm::vec3 const& max_); // Custom-constr.2 param
    //Triangle(glm::vec3 const& min_,glm::vec3 const& max_,std::string name_,Color color_); // Custom-constr.4 param
    ~Triangle();

    /* virtual */ float area() const override ;
    /* virtual */ float volume () const override ;  // Dreieck ist Fläche --wie soll das gehen ???  
    /* virtual */ std::ostream& print(std::ostream& os) const override;

  
    private:  //  private auch bei ableitenden Klassen oder protected oder auch public ??
    glm::vec3 e1_; 
    glm::vec3 e2_;
    glm::vec3 e3_;
};


#endif // TRIANGLE_HPP