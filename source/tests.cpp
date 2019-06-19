#define CATCH_CONFIG_RUNNER

#include <sphere.hpp>
#include <box.hpp>

#include <catch.hpp>

// * --------------- 5.1 und 5.2 --------------- * //
TEST_CASE("TestCase_1    5.1 und 5.2", "[aufgabe 5.1,5.2]") {

  Sphere sph1; 
  REQUIRE (sph1.volume() == Approx(M_PI * 4.0 / 3.0));


}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
