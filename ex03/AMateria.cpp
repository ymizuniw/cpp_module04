#include "includes/AMateria.hpp"
#include <iostream>

// AMateria(void);
// AMateria(AMateria const &materia);
// AMateria(std::string const &type);
// AMateria &operator=(AMateria const &materia);

AMateria::AMateria(void) : type_("default_materia") {
  std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &other) : type_(other.type_) {
  std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type_(type) {
  std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other) {
  if (this != &other) {
    type_ = other.type_;
  }
  return (*this);
}

// virtual ~AMateria(void);
// std::string const &getType(void) const;
// virtual AMateria *
// clone(void) const = 0; // all Materia should be able to clone() ed.
// virtual void use(ICharacter &target) = 0;

AMateria::~AMateria(void) {
  std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const { return (type_); }
