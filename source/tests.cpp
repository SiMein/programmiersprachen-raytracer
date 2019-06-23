#define CATCH_CONFIG_RUNNER

#include <sphere.hpp>
#include <box.hpp>

#include <catch.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

// * --------------- 5.1, 5.2, 5.3, 5.4, 5.5 --------------- * //
TEST_CASE("TestCase_1    5.1, 5.2, 5.3, 5.4, 5.5", "[aufgabe 5.1,5.2,5.3,5.4,5.5]") {


  Sphere sph1;                  // check area and volume-method with default-constr
  REQUIRE(sph1.volume() == Approx(4.18879f));
  REQUIRE(sph1.area() == Approx(12.56637f));
  
  Sphere sph2{{1.0,1.0,1.0},{11.0}}; // check custom-constr 
  REQUIRE(sph2.area() == Approx(1520.53088f));
  
  Sphere sph3{{1.0,1.0,1.0},{-11.0}};   // check custom-constr with borderlinecase in a method
  REQUIRE(sph3.volume() == Approx(-1.0));


  Box bo1;                     // check area and volume-method with default-constr
  REQUIRE(bo1.volume() == Approx(1.0));
  REQUIRE(bo1.area() == Approx(6.0));

  Box bo2{{1.0f,1.0f,1.0f}, {11.0f,11.0f,11.0f}};  // check custom-constr 
  REQUIRE(bo2.volume() == Approx(1000.0));

  Box bo3{{1.0f,1.0f,1.0f}, {-5.0f,11.0f,11.0f}};  // check custom-constr with borderlinecase in a method
  REQUIRE(bo3.area() == Approx(-1.0));


  
  Color co1{0.5,0.5,0.5};         // constr with 4 parameters

  Sphere sph4{{1.0,1.0,1.0},{11.0},"heinz", co1}; 
  Box bo4{{0.0f, 0.0f, 0.0f},{1.0f, 1.0f,1.0},"hugo",co1}; 
  //REQUIRE(bo1.name_ == "hugo"); // Attributzugriff auf name von abgeleiteter klasse hindurch zur basisklasse mgl., dafür aber 
  //muesste umstellen von protected auf public, oder ueber getter-methode in kindklasse weil d test klasse hier sich ausserhalb befindet
  //dafuer print ausgabe  aufg 5.4. vorgesehen ...

  std::cout << "\nprintout by call method print() \n";
  sph1.print(std::cout);
  sph4.print(std::cout); // Direkter aufruf der printmethode --achtung in-parameter hier beachten 
  bo1.print(std::cout); 
  bo2.print(std::cout);  
  std::cout << "\nprintout by call operator << \n";
  std::cout << sph1 << "\n";
  std::cout << sph4 << "\n";
  std::cout << bo1 << "\n";
  std::cout << bo2 << "\n";

}


TEST_CASE ("intersect_ray_sphere", "[intersect]"){
// Ray
glm::vec3 ray_origin{0.0f, 0.0f, 0.0f};
// ray direction has to be normalized !
// you can use :
// v = glm :: normalize ( some_vector )
glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};
// Sphere
glm::vec3 sphere_center{0.0f ,0.0f, 5.0f};
float sphere_radius{1.0f};
float distance = 0.0f;
auto result = glm::intersectRaySphere (ray_origin ,ray_direction ,sphere_center ,
sphere_radius * sphere_radius , // squared radius !!!
distance );

REQUIRE(distance == Approx (4.0f));

}


// * --------------- 5.x--------------- * //
TEST_CASE("TestCase_2    5.x", "[aufgabe 5.x]") {


}
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
