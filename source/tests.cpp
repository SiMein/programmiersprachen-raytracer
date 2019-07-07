#define CATCH_CONFIG_RUNNER

#include <sphere.hpp>
#include <box.hpp>
#include <triangle.hpp>
#include "material.hpp"

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


TEST_CASE (" TestCase_2    intersect_HitPoint_ray_sphere", "[p]"){
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
  auto result = glm::intersectRaySphere(ray_origin ,ray_direction ,sphere_center ,
  sphere_radius * sphere_radius , // squared radius !!!
  distance );

  REQUIRE(distance == Approx (4.0f));

  Color co1{1.0f,1.0f,1.0f}; 
  Ray r1{{0.0f,0.0f,0.0f},{1.0f,0.0f,0.0f}};
  Sphere s1{{1.0,0.0,0.0},{0.5},"franz", co1};

  std::cout << s1 << "\n  this last was s1 print out \n";
  HitPoint h1;
  h1 = s1.intersect_Hitpoint(r1);      // check, ob attribute in hitpoint uebertragen wurden bei treffer !!
  REQUIRE(h1.cross == true);
  REQUIRE(h1.t == 0.0f);
  REQUIRE(h1.name == "franz");
  REQUIRE(h1.co.r == 1.0f);   // Color-einzel-attrib-pruefung
  REQUIRE(h1.co.g == 1.0f);
  REQUIRE(h1.co.b == 1.0f);
  REQUIRE(h1.crossPoint.x == 0.5f);   // vec3-einzel-attrib-pruefung
  REQUIRE(h1.crossPoint.y == 0.0f);
  REQUIRE(h1.crossPoint.z == 0.0f);
  REQUIRE(h1.direction.x == 1.0f);   // vec3-einzel-attrib-pruefung
  REQUIRE(h1.direction.y == 0.0f);
  REQUIRE(h1.direction.z == 0.0f);

  HitPoint h2;
  Color co2{0.7f,0.7f,0.7f}; 
  Sphere s2{{5.5,1.0,8.0},{1.0},"schorsch", co2};
  h2 = s2.intersect_Hitpoint(r1);      // check, ob attribute in hitpoint uebertragen wurden wenn KEIN !! treffer
  REQUIRE(h2.cross == false);
  REQUIRE(h2.t == 0.0f);
  REQUIRE(h2.name == "default-HitPoint");
  REQUIRE(h2.co.r == 0.0f);   // Color-einzel-attrib-pruefung
  REQUIRE(h2.co.g == 0.0f);
  REQUIRE(h2.co.b == 0.0f);
  REQUIRE(h2.crossPoint.x == 0.0f);   // vec3-einzel-attrib-pruefung
  REQUIRE(h2.crossPoint.x == 0.0f);
  REQUIRE(h2.crossPoint.x == 0.0f);
  glm::vec3 test_vec3{0.0,0.0,0.0};   // alternative. -zu erwartendes Objekt vom typ vec3 erstellt
  REQUIRE(h2.direction == test_vec3); // dann (gesamt)-vergleich zweier vec3 objekte

}

// * --------------- 5.7--------------- * //
TEST_CASE("TestCase_3    5.7", "[aufgabe 5.7]") {

  std::cout << "\n  aufg 5.7  \n";
  Color red {255,0,0};
  glm::vec3 position{0.0f,0.0f,0.0f};

  // links statischer Typ             rechts dynamischer Typ
  std::shared_ptr <Sphere>s1 = std::make_shared <Sphere>(position, 1.2f,"sphere0", red);
    // zu s1 - direkter aufruf der sphereprintmethode, da auch mit sphere typisiert
  std::shared_ptr <Shape>s2 = std::make_shared <Sphere>(position, 1.2f,"sphere1", red);
    // zu s2 - statischer basisklassentyp , zur laufzeit wird mittels virtueller methode print 
    // die tatsaechliche klasse bzw abgeleitete klasse aufgerufen (dynamisch) 
// somit letzlich in beiden fällen printausgabe von printmethode aus sphere

  // Im Kontext der Vererbung erlauben statisch typisierte OO-Sprachen, dass die
  // dynamische Klasse einer Variablen eine von der statischen Klasse abgeleitete Klasse sein kann.
  
  //std::shared_ptr <Sphere>s3 = std::make_shared <Shape>(position, 1.2f,"sphere1", red);
   // zu s3 --das würde nicht gehen ,da für shape klasse nur konstruktor mit 2 parametern vorhanden

  //std::shared_ptr <Sphere>s4 = std::make_shared <Shape>();
   // zu s4 - das compiled garnicht erst richtig ,--fehler  tests.cpp:135:56: error: conversion from ‘shared_ptr<Shape>’ to non-scalar type ‘shared_ptr<Sphere>’ requested
   //std::shared_ptr <Sphere>s4 = std::make_shared <Shape>();

  s1->print(std::cout);
  s2->print(std::cout);

}

// * --------------- 5.8--------------- * //
TEST_CASE("TestCase_4    5.8", "[aufgabe 5.8]") {

  std::cout << "\n  aufg 5.8  \n";

  Color red{255,0, 0};
  glm::vec3 position{0.0f,0.0f,0.0f};

  std::cout << "\n  create s1   \n";
  Sphere* s1 = new Sphere{position ,1.5f,"sphere0",red} ; // per * erzeugung des objekts auf dem freestore
  std::cout << "\n  create s2   \n";
  Shape* s2 = new Sphere{position ,1.5f,"sphere1",red};
  std::cout << "\n  create b1   \n";
  Box* b1 = new Box; // per * erzeugung des objekts auf dem freestore
  std::cout << "  create b2   \n";
  Shape* b2 = new Box;

  std::cout << " printout s1 und s2    \n";
  s1->print(std::cout);
  s2->print(std::cout);

  std::cout << "\ndelete s1 : \n";
  delete s1;
  std::cout << "\ndelete s2 : \n";
  delete s2;

  std::cout << "\ndelete b1 : \n";
  delete b1;
  std::cout << "\ndelete b2 : \n";
  delete b2;
/*
bei erzeugung eines objektes wird immer standardmaessig erst der basisklassenkonstructor 
, dann der kinsklassenkonstructor aufgerufen */
/* 
 wenn kein virtual vor destruktor in shape, dann ausgabe:
delete s1 : 
I am the Sphere-Destruktor !I am the Shape-Destruktor !
delete s2 : 
I am the Shape-Destruktor !  
somit ist das verhalten des destructors davon abhängig davon wie das objekt erzeugt wurde !!
schlecht ,weil unberechenbar und im schlechten fall wird geloeschter speicher so weiter blockiert
*/
/*
wenn virtual vorm destruktor in shape steht, dann ausgabe:
delete s1 : 
I am the Sphere-Destruktor !I am the Shape-Destruktor !
delete s2 : 
I am the Sphere-Destruktor !I am the Shape-Destruktor !
delete b1 : 
I am the Box-Destruktor !I am the Shape-Destruktor !
delete b2 : 
I am the Box-Destruktor !I am the Shape-Destruktor !
somit unabhaenig von erzeugung des objektes ein gleichmaessig geregeltes destruktor-verhalten, gut
von unten nach oben --erst kindklasse dann elternklasse  !!
*/  

//1) delete expression        Destroys one non-array object created by a new-expression
//2) delete [] expression     Destroys an array created by a new[]-expression

// verhalten d construktors gehts schrittweise tiefer in die klassen, der 
// destructor genau entgegen schrittweise wieder herausgehen 
}



// * --------------- Aufgabenblatt 6  !!!!-------------- * //
TEST_CASE("TestCase_5    triangle-check aufg 6.2 ","[aufgabe 6.2]") {

  std::cout << "\n--------------- Aufgabenblatt 6  !!!!--------------\n";

  Triangle tri1;         // check area and volume-method tiangle !!!!    with default-constr
  REQUIRE(tri1.volume() == Approx(-1.0f));
  REQUIRE(tri1.area() == Approx(-1.0f));

  Ray r5;
  float fl10 = 6.0;
  Sphere s10;
  Box b10;
  Triangle t10;

  REQUIRE(s10.intersect(r5,fl10) == true);
  REQUIRE(b10.intersect(r5,fl10) == true);
  REQUIRE(t10.intersect(r5,fl10) == true);

  Material material1;
  //std::cout << material1;

}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
