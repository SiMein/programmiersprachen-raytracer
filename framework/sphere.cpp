#include "sphere.hpp"
#include <glm/vec3.hpp>
#include <iostream>

Sphere::Sphere() :      // default-constr-Sphere
  Shape::Shape{"Sphere"},
  center_{},    // {0.0f, 0.0f, 0.0f},
  radius_     {1.0f}{ /*std::cout << "I am the Sphere-construktor !"; */ }

Sphere::Sphere(glm::vec3 const& center,float radius) :      // custom-constr-Sphere  2 parameter
  Shape::Shape{"Sphere"},
  center_ {center},
  radius_ {radius}{/*std::cout << "I am the Sphere-contruktor !";*/}

Sphere::Sphere(glm::vec3 const& center,float radius,std::string name, std::shared_ptr<Material> const& ma_co) :      // custom-constr-Sphere  4 parameter
  Shape::Shape{name, ma_co},  // Parameter werden weitergereicht an den konstr der basisklasse für die entspr. parameter
  center_ {center},
  radius_ {radius}{/* std::cout << "I am the Sphere-contruktor !";*/}

Sphere::~Sphere(){
 // std::cout << "I am the Sphere-Destruktor !";
}


float Sphere::area() const {        // Formel checken !!!
  if(radius_ < 0){
    std::cout << "\nyour radius -it is negativ !\n";
    return -1.0f;
  }
  return 4*M_PI * std::pow(radius_, 2);
}

float Sphere::volume() const{  // Formel checken !!!
  if(radius_ < 0){
    std::cout << "\nyour radius -it is negativ !\n";
    return -1.0f;
  }
  return (4.0f/3.0f)* M_PI * std::pow(radius_, 3);
}

// warum t  distance auf 0 setzen ??
HitPoint Sphere::intersect(Ray const& r) const{
  float t1 = 0.0f;
  bool crossed = glm::intersectRaySphere(r.origin,glm::normalize(r.direction),center_,(radius_*radius_),t1);
  HitPoint h;
  if (crossed){
    h.cross = crossed;  // bool
    h.t = 0.0f;  // distance to cut
    h.name = name_;  // name des objektes das geschnitten wurde, auf d hier aufgerufenen sphere
    // h.co = color_;   DEAKTIVIERT WEGEN SHARED_PTR für MATERIAL// color des objektes das geschnitten wurde, auf d hier aufgerufenen sphere
    //glm::vec3 cro_p =
    h.crossPoint = r.origin + t1 * r.direction;  // berechnung nach vorgeg. formel aus aufg 5.6
    //glm::vec3 cro_p; // crosspoint
    h.direction = r.direction; // direction
  }
  return h;
}

std::ostream& Sphere::print(std::ostream& os) const{ 
  Shape::print(os);   // print methode der basisklasse wir mit augerufen -für basis attributausgabe
//  return os << "Center : " << center_.x << "\t" << center_.y << "\t" << center_.z << "\n"
//     << "Radius : " << radius_ << "\n";
}
