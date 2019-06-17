#ifndef BOX_HPP
#define BOX_HPP

class Box : public Shape { // abgeleitete Klasse und ableitende Klasse
    
    public:
    Box(); // Defaul-constr., mit default-Werten

    private:  //  private auch bei ableitenden Klassen oder protected oder auch public ??
    glm::vec3 max_; 
    glm::vec3 min_; 
}


#endif // BOX_HPP