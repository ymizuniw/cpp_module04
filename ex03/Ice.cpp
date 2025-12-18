#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {
  std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other.type_) {
  std::cout << "Ice copy-constructor called." << std::endl;
}

Ice &Ice::operator=(Ice const &other) {
  if (this != &other) {
    type_ = other.type_;
  }
  return (*this);
}

Ice::~Ice(void) { std::cout << "Ice destructor called." << std::endl; }

AMateria *Ice::clone(void) const {
  Ice *cp_ice = new Ice(*this);
  return (cp_ice);
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
