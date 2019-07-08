#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <set>
#include <map>
#include <memory>
#include <iostream>
#include <string>

#include "material.hpp"
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "triangle.hpp"

struct Scene {
  std::vector<std::shared_ptr<Material>>;
  std::set<std::shared_ptr<Material>>;
  std::map<std::string,std::shared_ptr<Material>>;.

};

static void get_SDF_File(std::string const& path,Scene& scene){// Freie fkt., bekommt als parameter den dateipfad und oeffnet diesen
    
}
#endif // SCENE_HPP