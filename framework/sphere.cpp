#include "sphere.hpp"
#include <glm/vec3.hpp>
#include <iostream>

Sphere::Sphere() :      // default-constr-Sphere
  Shape::Shape{"Sphere"},
  center_     {0.0f, 0.0f, 0.0f},
  radius_     {1.0f}{}

Sphere::Sphere(glm::vec3 const& center,float radius) :      // custom-constr-Sphere  2 parameter
  Shape::Shape{"Sphere"},
  center_ {center},
  radius_ {radius}{}

Sphere::Sphere(glm::vec3 const& center,float radius,std::string name,Color color) :      // custom-constr-Sphere  4 parameter
  Shape::Shape{name, color},  // Parameter werden weitergereicht an den konstr der basisklasse für die entspr. parameter
  center_ {center},
  radius_ {radius}{}


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

// rückgabe typ bool oder HitPoint  ?!   freie function ??
bool Sphere::intersect(Ray const& r, HitPoint& h) const{
                      //HitPoint Sphere::intersect(Ray const& r, float dist) const{
  bool crossed = glm::intersectRaySphere(r.origin,glm::normalize(r.direction),center_,(radius_*radius_),h.t);
  h.cross = crossed;
  return crossed;
}

std::ostream& Sphere::print(std::ostream& os) const{ 
  Shape::print(os);   // print methode der basisklasse wir mit augerufen -für basis attributausgabe
  os << "Center : " << center_.x << "\t" << center_.y << "\t" << center_.z << "\n"
     << "Radius : " << radius_ << "\n";
}
