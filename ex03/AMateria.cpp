#include "AMateria.hpp"
#include "includes/AMateria.hpp"
#include <iostream>

AMateria::AMateria(void) : type_("default") {
  std::cout << "AMateria constructor called." << std::endl;
}

AMateria::AMateria(std::string const &type) : type_(type) {
  std::cout << "AMateria parameterized constructor called." << std::endl;
}

AMateria::AMateria(AMateria const &other) : type_(other.type_) {
  std::cout << "AMateria copy-construcotr called." << std::endl;
}

AMateria::~AMateria(void) {
  std::cout << "AMateria destructor called." << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other) {
  if (this != &other) {
    type_ = other.type_;
  }
  return (*this);
}

std::string const &AMateria::getType(void) const { return (type_); }
