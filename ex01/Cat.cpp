#include "Cat.hpp"
#include <iomanip>
#include <iostream>

Cat::Cat(void) : Animal("Cat") {
  brain_ = new Brain();

  std::cout << std::setw(9) << std::right << "[Cat] ";
  std::cout << "constructor called" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other) {
  brain_ = other.brain_;
  std::cout << std::setw(9) << std::right << "[Cat] ";
  std::cout << "copy-constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other) {
  if (this != &other)
    Animal::operator=(other);
  return (*this);
}

Cat::~Cat(void) {
  std::cout << std::setw(9) << std::right << "[Cat] ";
  std::cout << "destructor called" << std::endl;
  delete brain_;
}

void Cat::makeSound(void) const { std::cout << "meaow" << std::endl; }

#ifdef DEBUG
void Cat::print_ideas(void) {
  for (size_t i = 0; i < 100; i++)
    std::cout << brain_->getIdea(i) << std::endl;
}
#endif
