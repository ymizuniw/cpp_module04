#include "Dog.hpp"
#include <iomanip>
#include <iostream>

Dog::Dog(void) : Animal("Dog") {
  brain_ = new Brain();
  std::cout << std::setw(9) << std::right << "[Dog] ";
  std::cout << "constructor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other) {
  brain_ = new Brain(*other.brain_);
  std::cout << std::setw(9) << std::right << "[Dog] ";
  std::cout << "copy-constructor called" << std::endl;
}

Dog const &Dog::operator=(Dog const &other) {
  if (this != &other) {
    Animal::operator=(other);
    delete brain_;
    brain_ = new Brain(*other.brain_);
  }
  return (*this);
}

Dog::~Dog(void) {
  std::cout << std::setw(9) << std::right << "[Dog] ";
  std::cout << "destructor called" << std::endl;
  delete brain_;
}

void Dog::makeSound(void) const { std::cout << "bowwow" << std::endl; }

#ifdef DEBUG
void Dog::print_ideas(void) {
  for (size_t i = 0; i < 100; i++)
    std::cout << brain_->getIdea(i) << std::endl;
}
#endif
