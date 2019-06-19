#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <ctgmath>
#include <string>

class Shape {
    public:
    Shape(std::string const& name = "default-name-shape"); // default-constr.

    virtual float area() const = 0; // method wird hier in abstrakter Klasse zugesichert, spezifische Implement dann in child-classes 
    virtual float volume() const = 0; // dito                       // daher spez. Implem in cpp von shape NICHT nötig 

    protected:

    std::string name_;
};

#endif // SHAPE_HPP