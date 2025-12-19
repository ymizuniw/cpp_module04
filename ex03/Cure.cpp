#include "includes/Cure.hpp"
#include "includes/AMateria.hpp"
#include <iostream>
// public:
//   Cure(void);
//   Cure(Cure const &other);
//   Cure &operator=(Cure const &other);
//   ~Cure(void);
//   // AMateria *clone(void) const;
//   // void use(ICharacter &target);

Cure::Cure(void) : AMateria() {
  std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other.type_) {
  std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &other) {
  (void)other;
  return (*this);
}

Cure::~Cure(void) { std::cout << "Cure destructor called" << std::endl; }

AMateria *Cure::clone(void) const {
  AMateria *cure = new Cure(*this);
  return (cure);
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
