#ifndef HITPOINT_HPP
#define HITPOINT_HPP

#include <string>
#include "color.hpp"
#include <glm/vec3.hpp>
#include <iostream>

struct HitPoint {
    bool cross = false;
    float t = 0.0;
    std::string name = "default-HitPoint";
    Color co{Color{0.0,0.0,0.0}};
    glm::vec3 crossPoint{0.0,0.0,0.0};
    glm::vec3 direction{0.0,0.0,0.0};
};

#endif // HITPOINT_HPP