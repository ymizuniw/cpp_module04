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
// function: makeSound() It will print an appropriate sound (cats don’t bark).
// 8
// C++ - Module 04 Subtype Polymorphism, Abstract Classes, and Interfaces
// Running this code should print the specific sounds of the Dog and Cat
// classes, not the Animal’s.

// To ensure you understood how it works, implement a WrongCat class that
// inherits from a WrongAnimal class. If you replace the Animal and the Cat by
// the wrong ones in the code above, the WrongCat should output the WrongAnimal
// sound. Implement and turn in more tests than the ones given above.

int main(void) {
  const Animal *meta = new Animal(); // call animal df constructor
  const Animal *j = new Dog();       // call animal/dog constructor
  const Animal *i = new Cat();       // call animal/cat constructor
  const WrongAnimal *wa = new WrongAnimal();//call 
  const WrongAnimal *wc = new WrongCat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  meta->makeSound();
  wa->makeSound();
  wc->makeSound();
  return 0;
}
