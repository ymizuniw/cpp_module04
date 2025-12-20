#include "includes/AMateria.hpp"
#include "includes/Character.hpp"
#include "includes/Cure.hpp"
#include "includes/ICharacter.hpp"
#include "includes/IMateriaSource.hpp"
#include "includes/Ice.hpp"
#include "includes/MateriaSource.hpp"
#include <iostream>

int main(void) {
  std::cout << "============MateriaSource===========" << std::endl;

  std::cout << "[Default Ctor] ";
  MateriaSource mtsrc;
  std::cout << "[Copy Ctor] ";
  MateriaSource mtsrc_cp(mtsrc);
  std::cout << "==========AMateria==========" << std::endl;
  AMateria *ice = new Ice();
  AMateria *cure = new Cure();
  std::cout << "============================" << std::endl;
  mtsrc.learnMateria(ice);
  mtsrc.learnMateria(cure);
  std::cout << "[Copy Assignment op] " << std::endl;
  mtsrc_cp = mtsrc;
  AMateria *icemat = mtsrc.createMateria("ice");
  AMateria *curemat = mtsrc.createMateria("cure");
  AMateria *icemat2 = mtsrc_cp.createMateria("ice");
  AMateria *curemat2 = mtsrc_cp.createMateria("cure");
  if (icemat->getType() == icemat2->getType() &&
      curemat->getType() == curemat2->getType())
    std::cout << "[Type Corresponds!]" << std::endl;
  else
    std::cout << "[Type mismatched!]" << std::endl;
  return (0);
}
