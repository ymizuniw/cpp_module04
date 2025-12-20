#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog") {
  std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal("Dog") {
  if (this != &other) {
    Animal::operator=(other);
  }
  std::cout << "Dog copy-constructor called" << std::endl;
}

Dog const &Dog::operator=(Dog const &other) {
  if (this != &other)
    Animal::operator=(other);
  return (*this);
}

Dog::~Dog(void) { std::cout << "Dog destructor called" << std::endl; }

void Dog::makeSound(void) const { std::cout << "bowwow" << std::endl; }
