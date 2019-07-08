#include "shape.hpp"



Shape::Shape(std::string const& name): 
    name_ {name}{/*std::cout << "I am the Shape-contructor !";*/}

Shape::Shape(std::string const& name, std::shared_ptr<Material> const& ma_co):
    name_ {name},
    ma_co_ {ma_co}{/* std::cout << "I am the Shape-contructor !";*/}  // da ein struct, muss init direkt erfolgen in cpp und hpp !!!!

Shape::~Shape(){
  //  std::cout << "I am the Shape-Destruktor !";
}

std::ostream& Shape::print(std::ostream& os) const{     // Printausgabe der Attrib von Shape-- weitere print-attrib. siehe Kindklassen
    os << "Shape-Name : " << name_ << "\n" << "Shape-Material : " << *ma_co_ << "\n";  // *ma_co_ dereferenz., weil zeiger
    return os;
}

std::ostream& operator <<(std::ostream& os,Shape const& s){  // free Operator-Overloading
    return s.print(os);
}