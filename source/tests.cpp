#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

// * --------------- 5.1 und 5.2 --------------- * //
TEST_CASE("TestCase_1    5.1 und 5.2", "[aufgabe 5.1,5.2]") {

  Sphere sph1; 
  REQUIRE (sph1.center_ == 0.0f);
  REQUIRE (sph1.center_ == 0.0f);
  REQUIRE (sph1.center_ == 0.0f);
  REQUIRE (sph1.radius_ == 1.0f);

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
