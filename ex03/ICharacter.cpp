#include "includes/ICharacter.hpp"
#include <ICharacter.hpp>
#include <iostream>

ICharacter::ICharacter(void) {
  std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter(ICharacter const &other) { (void)other; }

ICharacter &ICharacter::operator=(ICharacter const &other) {
  if (this != &other)
    *this = other;
  return (*this);
}

ICharacter::~ICharacter(void) {
  std::cout << "ICharacter destructor called" << std::endl;
}
