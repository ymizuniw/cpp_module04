#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

// For every exercise, you have to provide the most complete tests you can.
// Constructors and destructors of each class must display specific messages.
// Don’t use the same message for all classes. Start by implementing a simple
// base class called Animal. It has one protected attribute: • std::string type;
// Implement a Dog class that inherits from Animal.
// Implement a Cat class that inherits from Animal.
// These two derived classes must set their type field depending on their name.
// Then, the Dog’s type will be initialized to "Dog", and the Cat’s type will be
// initialized to "Cat". The type of the Animal class can be left empty or set
// to the value of your choice. Every animal must be able to use the member
// function: makeSound() It will print an appropriate sound (Cats don’t bark).
// 8
// C++ - Module 04 Subtype Polymorphism, Abstract Classes, and Interfaces
// Running this code should print the specific sounds of the Dog and Cat
// classes, not the Animal’s.

// To ensure you understood how it works, implement a WrongCat class that
// inherits from a WrongAnimal class. If you replace the Animal and the Cat by
// the wrong ones in the code above, the WrongCat should output the WrongAnimal
// sound. Implement and turn in more tests than the ones given above.

int ani_ocf_test(void) {
  Animal ani1;       // default constructor
  Animal ani2(ani1); // copy constructor
  Animal ani3;
  ani3 = ani1; // copy assignment
  int type_ok = 0;
  if (ani1.getType() == "Animal" && ani2.getType() == "Animal" &&
      ani3.getType() == "Animal")
    type_ok = 1;
  return (type_ok);
  // default destructor
}

int Dog_ocf_test(void) {
  Dog Dog1;       // default constructor
  Dog Dog2(Dog1); // copy constructor
  Dog Dog3;
  Dog3 = Dog1; // copy assignment
  int type_ok = 0;
  if (Dog1.getType() == "Dog" && Dog2.getType() == "Dog" &&
      Dog3.getType() == "Dog")
    type_ok = 1;
  return (type_ok);
  // default destructor
}

int Cat_ocf_test(void) {
  Cat Cat1;       // default constructor
  Cat Cat2(Cat1); // copy constructor
  Cat Cat3;
  Cat3 = Cat1; // copy assignment
  int type_ok = 0;
  if (Cat1.getType() == "Cat" && Cat2.getType() == "Cat" &&
      Cat3.getType() == "Cat")
    type_ok = 1;
  return (type_ok);
  // default destructor
}

int wani_ocf_test(void) {
  WrongAnimal wani1;        // default constructor
  WrongAnimal wani2(wani1); // copy constructor
  WrongAnimal wani3;
  wani3 = wani1; // copy assignment
  int type_ok = 0;
  if (wani1.getType() == "WrongAnimal" && wani2.getType() == "WrongAnimal" &&
      wani3.getType() == "WrongAnimal")
    type_ok = 1;
  return (type_ok);
  // default destructor
}

int WrongCat_ocf_test(void) {
  WrongCat WrongCat1;            // default constructor
  WrongCat WrongCat2(WrongCat1); // copy constructor
  WrongCat WrongCat3;
  WrongCat3 = WrongCat1; // copy assignment
  int type_ok = 0;
  if (WrongCat1.getType() == "WrongCat" && WrongCat2.getType() == "WrongCat" &&
      WrongCat3.getType() == "WrongCat")
    type_ok = 1;
  return (type_ok);
  // default destructor
}

int Animal_makeSound_test(void) {
  Animal animal1;
  animal1.makeSound();
  return (1);
}

int Dog_makeSound_test(void) {
  Dog Dog1;
  Dog1.makeSound();
  return (1);
}

int Cat_makeSound_test(void) {
  Cat Cat1;
  Cat1.makeSound();
  return (1);
}

int wrongAnimal_makeSound_test(void) {
  Cat Cat1;
  Cat1.makeSound();
  return (1);
}

int wrongCat_makeSound_test(void) {
  WrongCat WrongCat1;
  WrongCat1.makeSound();
  return (1);
}

int main(void) {
  std::cout << "=====================AnimalTest====================="
            << std::endl;
  int type_ok = ani_ocf_test();
  if (!type_ok) {
    std::cout << "ERROR!" << std::endl;
    return (1);
  }
  std::cout << "=====================DoggyTest====================="
            << std::endl;
  int Dog_type_ok = Dog_ocf_test();
  if (!Dog_type_ok) {
    std::cout << "ERROR!" << std::endl;
    return (1);
  }
  Dog_makeSound_test();

  std::cout << "=====================CattyTest====================="
            << std::endl;
  int Cat_type_ok = Cat_ocf_test();
  if (!Cat_type_ok) {
    std::cout << "ERROR!" << std::endl;
    return (1);
  }
  Cat_makeSound_test();

  std::cout << "=====================WrongAnimalTest====================="
            << std::endl;
  int wani_type_ok = wani_ocf_test();
  if (!wani_type_ok) {
    std::cout << "ERROR!" << std::endl;
    return (1);
  }
  wrongAnimal_makeSound_test();

  std::cout << "=====================WrongCattyTest====================="
            << std::endl;
  int wrongCat_type_ok = WrongCat_ocf_test();
  if (!wrongCat_type_ok) {
    std::cout << "ERROR!" << std::endl;
    return (1);
  }
  wrongCat_makeSound_test();
  std::cout << "Main Exits..." << std::endl;
  return 0;
}
