#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {
  std::cout << "Cure constructor called." << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other.type_) {
  std::cout << "Cure copy-constructor called." << std::endl;
}

Cure &Cure::operator=(Cure const &other) {
  if (this != &other) {
    type_ = other.type_;
  }
  return (*this);
}

Cure::~Cure(void) { std::cout << "Cure destructor called." << std::endl; }

AMateria *Cure::clone(void) const {
  AMateria *cure_cp = new Cure(*this);
  return (cure_cp);
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
