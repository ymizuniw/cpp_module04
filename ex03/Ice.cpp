#include "Ice.hpp"
#include "print_utils.hpp"

Ice::Ice(void) : AMateria("ice") { print_msg("Ice constructor called."); }

Ice::Ice(Ice const &other) : AMateria(other.type_) {
  print_msg("Ice copy-constructor called.");
}

Ice &Ice::operator=(Ice const &other) {
  if (this != &other) {
    type_ = other.type_;
  }
  return (*this);
}

Ice::~Ice(void) { print_msg("Ice destructor called."); }

AMateria *Ice::clone(void) const {
  Ice *cp_ice = new Ice(*this);
  return (cp_ice);
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
