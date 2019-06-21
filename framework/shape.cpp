#include "shape.hpp"


Shape::Shape(std::string const& name): 
    name_ {name}{}

Shape::Shape(std::string const& name, Color const& color):
    name_ {name},
    color_ {Color{0.0,0.0,0.0}}{}  // da ein struct, muss init direkt erfolgen in cpp und hpp !!!!
