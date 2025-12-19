#include "includes/Ice.hpp"
#include "includes/AMateria.hpp"
#include <iostream>

// public:
// Ice(void);
// Ice(Ice const &other);
// Ice &operator=(Ice const &other);
// ~Ice(void);
// //   AMateria *clone(void) const;
// //   void use(ICharacter &target);

Ice::Ice(void) : AMateria() {
  std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other.type_) {
  std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(Ice const &other) {
  (void)other;
  return (*this);
}

Ice::~Ice(void) { std::cout << "Ice destructor called" << std::endl; }

AMateria *Ice::clone(void) const {
  AMateria *ice = new Ice(*this);
  return (ice);
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
