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

#include <fstream>
#include <sstream>


struct Scene {
  std::vector<std::shared_ptr<Material>> vec_mat;
  std::set<std::shared_ptr<Material>> set_mat;
  std::map<std::string,std::shared_ptr<Material>> map_mat;

};

static void get_SDF_File(std::string const& path,Scene& scene){// Freie fkt., bekommt als parameter den dateipfad und oeffnet diesen
  std::ifstream in_file(path);    

  std::string line_buffer;

  while(std::getline(in_file, line_buffer)) {
    std::istringstream current_line_string_stream(line_buffer);
    std::string identifier;
    current_line_string_stream >> identifier;

    if( "define" == identifier ) {
      current_line_string_stream >> identifier;
      
      if("material" == identifier) {
        //....
        float ka_red, ka_green, ka_blue;
        current_line_string_stream >> ka_red;
        current_line_string_stream >> ka_green;

      }
    }
  }


  in_file.close();
}

#endif // SCENE_HPP