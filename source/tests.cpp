#define CATCH_CONFIG_RUNNER

#include <sphere.hpp>
#include <box.hpp>

#include <catch.hpp>

// * --------------- 5.1 und 5.2 --------------- * //
TEST_CASE("TestCase_1    5.1 und 5.2", "[aufgabe 5.1,5.2]") {


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

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
