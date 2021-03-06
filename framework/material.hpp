#ifndef MATERIAL_HPP
#define MATERIAL_HPP
                    // material struct alles in .hpp   .cpp nicht notwendig  //
#include <string>
#include "color.hpp"
#include <iostream>

struct Material{
    std::string name = "default material";
    Color ka = {0.33,0.33,0.33}; //Materialkoeffizienten ka,kd,ks
    Color kd = {0.44,0.44,0.44};
    Color ks = {0.55,0.55,0.55};
    float m = 0.0;  // Spekularreflexionsexponenten

    friend std::ostream& operator<<(std::ostream& os, Material const& m1){ // geht nur mit friend, + 2 referenz-args
    
    return os << "Name : " << m1.name << "\n"
                "ka : " << m1.ka <<       // standard printout für einzelfarben r,g,b schon in color implementiert
                "kd : " << m1.kd <<
                "ks : " << m1.ks << 
                "m : " << m1.m << "\n";


 //   return os << "Center : " << center_.x << "\t" << center_.y << "\t" << center_.z << "\n"
 //    << "Radius : " << radius_ << "\n";

    }

};

#endif // MATERIAL_HPP