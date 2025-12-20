#include "includes/AMateria.hpp"
#include "includes/Character.hpp"
#include "includes/Cure.hpp"
#include "includes/Ice.hpp"
#include "includes/MateriaSource.hpp"
#include <iostream>

int main(void) {
  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice()); // template ?
  src->learnMateria(new Cure());

  // createMateria() and ICharacter::equip()
  ICharacter *me = new Character("me"); // only copy ICharacter part?
  AMateria *ice;
  AMateria *cure;

  ice = src->createMateria("ice"); // return clone of materia.
  cure = src->createMateria("cure");
  me->equip(ice);
  me->equip(cure);
  ICharacter *bob = new Character("bob");
  me->use(0, *bob); // use ice

  AMateria *stash = me->getMateria(0);
  me->unequip(0);
  me->use(0, *bob); // use ice
  me->equip(stash);
  me->use(0, *bob); // use ice
  me->use(1, *bob); // use cure
  // delete stash;
  AMateria *cure2 = src->createMateria("cure");
  bob->equip(cure2);
  bob->use(0, *me);
  std::cout << "[ delete me ]" << std::endl;
  delete me;
  std::cout << "[ delete bob ]" << std::endl;
  delete bob;
  std::cout << "[ delete src ]" << std::endl;
  delete src;
  return (0);
}
