#include "Animal.hpp"
#include <iomanip>
#include <iostream>

Animal::Animal(void) : type_("Animal") {
  std::cout << std::setw(9) << std::right << "[Animal] ";
  std::cout << "default constructor called" << std::endl;
}

Animal::Animal(std::string type_) : type_(type_) {
  std::cout << std::setw(9) << std::right << "[Animal] ";
  std::cout << "parameterized constructor called" << std::endl;
}

Animal::Animal(Animal const &other) : type_(other.type_) {
  std::cout << std::setw(9) << std::right << "[Animal] ";
  std::cout << "copy-constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &other) {
  if (this != &other)
    type_ = other.type_;
  return (*this);
}

Animal::~Animal(void) {
  std::cout << std::setw(9) << std::right << "[Animal] ";
  std::cout << "destructor called" << std::endl;
}

void Animal::makeSound(void) const { std::cout << "Animal!" << std::endl; }

std::string Animal::getType(void) const { return (type_); }

#ifdef DEBUG
void Animal::print_ideas(void) { ; }
#endif
