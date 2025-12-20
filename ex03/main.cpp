#include "includes/AMateria.hpp"
#include "includes/Character.hpp"
#include "includes/Cure.hpp"
#include "includes/ICharacter.hpp"
#include "includes/IMateriaSource.hpp"
#include "includes/Ice.hpp"
#include "includes/MateriaSource.hpp"

int main(void) {

  // MateriaSource
  IMateriaSource *source = new MateriaSource();

  // learn
  source->learnMateria(new Ice());
  source->learnMateria(new Cure());
  source->learnMateria(new Ice());
  source->learnMateria(new Cure());

  // over learning
  AMateria *olice = new Ice();
  source->learnMateria(olice);

  // create
  AMateria *ices[10];
  for (int i = 0; i < 10; i++) {
    AMateria *ice = source->createMateria("ice"); // lower case ice.
    ices[i] = ice;
  }

  AMateria *cures[10];
  for (int j = 0; j < 10; j++) {
    AMateria *cure = source->createMateria("cure");
    cures[j] = cure;
  }

  int i = 0;
  int j = 0;
  // Character
  ICharacter *bob = new Character("bob");
  ICharacter *me = new Character("me");
  // ICharacter *jenny = new Character("jenny");
  // equip
  bob->equip(ices[i++]);
  bob->equip(ices[i++]);
  bob->equip(ices[i++]);
  bob->equip(ices[i++]);
  bob->equip(cures[j]); // cannnot equip
  // unequip
  AMateria *stash = bob->getMateria(0);
  bob->unequip(0);

  me->equip(cures[j++]);
  me->use(0, *bob);
  // use
  for (int k = 0; k < 5;
       k++) { // it also test unequipped slot , and out or slot range idx 4
    bob->use(k, *me);
  }
  for (; i < 10; i++) {
    delete ices[i];
  }
  for (; j < 10; j++) {
    delete cures[j];
  }
  // std::cout << "reached!" << std::endl;
  delete source;
  delete olice;
  delete bob;
  delete me;
  delete stash;
  return (0);
}
