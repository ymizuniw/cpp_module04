#include "includes/AMateria.hpp"
#include "includes/Character.hpp"
#include "includes/Cure.hpp"
#include "includes/ICharacter.hpp"
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

  std::cout << "===============Character===============" << std::endl;
  std::cout << "[Default Ctor] ";
  Character Ch1;
  std::cout << "[Param Ctor] ";
  Character Ch2("Tom");
  std::cout << "[Copy Ctor] ";
  Character Ch3(Ch1);
  if (Ch3.getName() == Ch1.getName())
    std::cout << "[Name Copied!]" << std::endl;
  else
    std::cout << "[Name Mismatch!]" << std::endl;
  Character Ch4("Cathy");
  Ch4.equip(icemat);
  Ch4.equip(curemat);
  Ch1 = Ch4;

  std::cout << "==========SlotCopy===========" << std::endl;
  std::cout << "[" << Ch4.getName() << "]" << std::endl;
  Ch4.use(0, Ch2);
  Ch4.use(1, Ch2);
  std::cout << "[" << Ch1.getName() << "]" << std::endl;
  Ch1.use(0, Ch2);
  Ch1.use(1, Ch2);
  std::cout << std::endl;

  delete icemat2;
  delete curemat2;
  return (0);
}
