#ifndef HITPOINT_HPP
#define HITPOINT_HPP

#include <string>
#include "color.hpp"
#include <glm/vec3.hpp>
#include <iostream>

struct HitPoint {
    bool cross;
    float t;
    std::string name;
    Color co{Color{0.0,0.0,0.0}};
    glm::vec3 crossPoint;
    // direction  to do
};

#endif // HITPOINT_HPP