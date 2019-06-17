#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape {
    public:
    Shape(); // default-constr.

    virtual float area() const = 0; // method wird hier in abstrakter Klasse zugesichert, spezifische Implement dann in child-classes 
    virtual float volume() const = 0; // dito                       // daher spez. Implem in cpp von shape NICHT nötig 
};

#endif // SHAPE_HPP