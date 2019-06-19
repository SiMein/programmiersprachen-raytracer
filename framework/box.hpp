#ifndef BOX_HPP
#define BOX_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

class Box : public Shape { // abgeleitete Klasse und ableitende Klasse
    
    public:
    Box(); // Defaul-constr., mit default-Werten
    Box(glm::vec3 const& min_,glm::vec3 const& max_); // Custom-constr.

    /* virtual */ float area() const override ;
    /* virtual */ float volume () const override ;


    
    
    private:  //  private auch bei ableitenden Klassen oder protected oder auch public ??
    glm::vec3 max_; 
    glm::vec3 min_; 
};


#endif // BOX_HPP