#include "shape.hpp"


Shape::Shape(std::string const& name): 
    name_ {name}{/*std::cout << "I am the Shape-contructor !";*/}

Shape::Shape(std::string const& name, Color const& color):
    name_ {name},
    color_ {color}{/* std::cout << "I am the Shape-contructor !";*/}  // da ein struct, muss init direkt erfolgen in cpp und hpp !!!!

Shape::~Shape(){
  //  std::cout << "I am the Shape-Destruktor !";
}

std::ostream& Shape::print(std::ostream& os) const{     // Printausgabe der Attrib von Shape-- weitere print-attrib. siehe Kindklassen
    os << "Name : " << name_ << "\n" << "Color : " << color_.r << "\t" << color_.g << "\t"
       << color_.b << "\n";
    return os;
}

std::ostream& operator <<(std::ostream& os,Shape const& s){  // free Operator-Overloading
    return s.print(os);
}