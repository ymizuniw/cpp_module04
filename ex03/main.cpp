#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main(void) {
  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  // src->learnMateria(new Cure());

  // // createMateria() and ICharacter::equip()
  // ICharacter *me = new Character("me"); // only copy ICharacter part?
  // AMateria *tmp;
  // tmp = src->createMateria("ice"); // return clone of materia.
  // me->equip(tmp);
  // delete tmp;
  // tmp = src->createMateria("cure");
  // me->equip(tmp);
  // delete tmp;
  // // use() materia to bob.
  // ICharacter *bob = new Character("bob");
  // me->use(0, *bob); // use ice
  // me->use(1, *bob); // use cure
  // delete me;
  // delete bob;
  delete src;
  return (0);
}
