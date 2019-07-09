#include "box.hpp"
#include <glm/vec3.hpp>
#include <cmath>
#include <iostream>


Box::Box() :      // default-constr-Sphere
  Shape::Shape{"Box"},    // hier uebertragung des Strings "Box" in die Basisklasse als name-parameter
  min_ {0.0f, 0.0f, 0.0f},
  max_ {1.0f, 1.0f,1.0}{/*std::cout << "I am the Box-contructor !";*/}

Box::Box(glm::vec3 const& min,glm::vec3 const& max) :   // custom-constr-Sphere 2 param
  Shape::Shape{"Box"},
  min_ {min},
  max_ {max}{/*std::cout << "I am the Box-contructor !";*/}

Box::Box(glm::vec3 const& min,glm::vec3 const& max,std::string name, std::shared_ptr<Material> const& ma_co) :  // custom-constr-Sphere 4 param
  Shape::Shape{name,ma_co},  // Parameter werden weitergereicht an den konstr der basisklasse für die entspr. parameter
  min_ {min},
  max_ {max}{/*std::cout << "I am the Box-contructor !";*/}

Box::~Box(){
 // std::cout << "I am the Box-Destruktor !";
}


float Box::area() const {        // Formel checken !!!

  if((min_.x > max_.x) || (min_.y > max_.y) || (min_.z > max_.z)){
    std::cout << "\nyour min and max values are incorrect !\n";
    return -1.0f;
  } 
  float x = max_.x - min_.x;
  float y = max_.y - min_.y;
  float z = max_.z - min_.z;
  
  return 2*(x*y + x*z + y*z);
}

float Box::volume() const {  // Formel checken !!!

  if((min_.x > max_.x) || (min_.y > max_.y) || (min_.z > max_.z)){
    std::cout << "\nyour min and max values are incorrect !\n";
    return -1.0f;
  } 
  float x = max_.x - min_.x;
  float y = max_.y - min_.y;
  float z = max_.z - min_.z;
  
  return (x*y*z);
  
}


HitPoint Box::intersect(Ray const& ray) const{

  HitPoint h;

  if((min_.x > max_.x) || (min_.y > max_.y) || (min_.z > max_.z)){
    std::cout << "\nyour min and max values are incorrect !\n";
    return h;
  } 
  float t1 = 0.0f;
  bool crossed = false; //= glm::intersectRaySphere(r.origin,glm::normalize(r.direction),center_,(radius_*radius_),t1);
  if (crossed){
    h.cross = crossed;  // bool
    h.t = 0.0f;  // distance to cut
    h.name = name_;  // name des objektes das geschnitten wurde, auf d hier aufgerufenen sphere
    // h.co = color_;   DEAKTIVIERT WEGEN SHARED_PTR für MATERIAL// color des objektes das geschnitten wurde, auf d hier aufgerufenen sphere
    //glm::vec3 cro_p =
    //h.crossPoint = r.origin + t1 * r.direction;  // berechnung nach vorgeg. formel aus aufg 5.6
    //glm::vec3 cro_p; // crosspoint
    //h.direction = r.direction; // direction
  }
  return h;
}

std::ostream& Box::print(std::ostream& os) const {
  Shape::print(os); // print methode der basisklasse wir mit augerufen -für basis attributausgabe
  return os << "Minimum : " << min_.x << "\t" << min_.y << "\t" << min_.z << "\n"
     << "Maximum : " << max_.x << "\t" << max_.y << "\t" << max_.z << "\n";
}

