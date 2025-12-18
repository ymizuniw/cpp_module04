#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : type_("Animal") {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type_) : type_(type_) {
  std::cout << "Animal parameterized constructor called" << std::endl;
}

Animal::Animal(Animal const &other) : type_(other.type_) {
  std::cout << "Animal copy-constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &other) {
  if (this != &other)
    type_ = other.type_;
  return (*this);
}

Animal::~Animal(void) { std::cout << "Animal destructor called" << std::endl; }

void Animal::makeSound(void) const {
  std::cout << "Animal Animal!" << std::endl;
}

std::string Animal::getType(void) const { return (type_); }
