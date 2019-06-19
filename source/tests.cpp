#define CATCH_CONFIG_RUNNER

#include <sphere.hpp>
#include <box.hpp>

#include <catch.hpp>

// * --------------- 5.1 und 5.2 --------------- * //
TEST_CASE("TestCase_1    5.1 und 5.2", "[aufgabe 5.1,5.2]") {


  Sphere sph1; 
  REQUIRE(sph1.volume() == Approx(4.18879f));
  REQUIRE(sph1.area() == Approx(12.56637f));
  
  Sphere sph2{{1.0,1.0,1.0},{11.0}};

  Box bo1;
  REQUIRE(bo1.volume() == Approx(1.0));
  REQUIRE(bo1.area() == Approx(1.0));

  Box bo2{{1.0f,1.0f,1.0f}, {11.0f,11.0f,11.0f}};


}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
