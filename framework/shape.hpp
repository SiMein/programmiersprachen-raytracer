#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <ctgmath>
#include <string>
#include "color.hpp"
#include "ray.hpp"
#include <glm/gtx/intersect.hpp>
#include "hitPoint.hpp"
#include "material.hpp"
#include <memory>

class Shape {
    public:
    Shape(std::string const& name = "default-name-shape"); // default-constr. wenn kein parameter -defaultname zuweisung, sonst parametername
    Shape(std::string const& name, std::shared_ptr<Material> const& ma_co);
    virtual ~Shape(); // wie gewohnt auch bei destructor in .hpp die Signatur und genaue implement. in .cpp 

    virtual float area() const = 0; // method wird hier in abstrakter Klasse zugesichert, spezifische Implement dann in child-classes 
    virtual float volume() const = 0; // dito                       // daher spez. Implem in cpp von shape NICHT nötig 
    virtual HitPoint intersect(Ray const& ray) const = 0;
    virtual std::ostream& print(std::ostream& os) const;
   
    
    protected:
                                // Basisattribute --auch für abgeleitete Klassen hier init.
    std::string name_;
    std::shared_ptr<Material> ma_co_;
};

std::ostream& operator <<(std::ostream& os,Shape const& s);  // freie fkt für shape printout

#endif // SHAPE_HPP