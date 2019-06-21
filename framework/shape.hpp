#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <ctgmath>
#include <string>
#include "color.hpp"

class Shape {
    public:
    Shape(std::string const& name = "default-name-shape"); // default-constr. wenn kein parameter -defaultname zuweisung, sonst parametername
    Shape(std::string const& name, Color const& color);

    virtual float area() const = 0; // method wird hier in abstrakter Klasse zugesichert, spezifische Implement dann in child-classes 
    virtual float volume() const = 0; // dito                       // daher spez. Implem in cpp von shape NICHT nötig 

    public:
    //protected:
                                // Basisattribute --auch für abgeleitete Klassen hier init.
    std::string name_;
    Color color_{0.0,0.0,0.0}; // da ein struct, muss init direkt erfolgen in cpp und hpp !!!!
};

#endif // SHAPE_HPP