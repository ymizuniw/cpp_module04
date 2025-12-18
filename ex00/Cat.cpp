#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat") {
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other) {
  std::cout << "Cat copy-constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other) {
  if (this != &other)
    Animal::operator=(other);
  return (*this);
}

Cat::~Cat(void) { std::cout << "Cat destructor called" << std::endl; }

void Cat::makeSound(void) const { std::cout << "meaow" << std::endl; }
