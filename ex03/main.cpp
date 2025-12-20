#include "includes/AMateria.hpp"
#include "includes/Character.hpp"
#include "includes/Cure.hpp"
#include "includes/ICharacter.hpp"
#include "includes/IMateriaSource.hpp"
#include "includes/Ice.hpp"
#include "includes/MateriaSource.hpp"

int main(void) {

  /* ============================================================
   * 1. MateriaSource basic behavior
   * ============================================================ */
  IMateriaSource *source = new MateriaSource();

  source->learnMateria(new Ice());
  source->learnMateria(new Cure());
  source->learnMateria(new Ice());
  source->learnMateria(new Cure());

  // over-learn (should be ignored, not deleted internally)
  AMateria *overflow = new Ice();
  source->learnMateria(overflow);

  /* ============================================================
   * 2. Character copy semantics (Rule of Three)
   * ============================================================ */
  {
    Character a("a");
    a.equip(source->createMateria("ice"));

    Character b(a); // copy constructor
    Character c("c");
    c = a; // copy assignment

    a.use(0, b);
    b.use(0, a);
    c.use(0, a);
  }

  /* ============================================================
   * 3. createMateria stress test
   * ============================================================ */
  AMateria *ices[10];
  AMateria *cures[10];

  for (int i = 0; i < 10; i++)
    ices[i] = source->createMateria("ice");

  for (int i = 0; i < 10; i++)
    cures[i] = source->createMateria("cure");

  /* ============================================================
   * 4. equip / unequip / use boundary test
   * ============================================================ */
  ICharacter *bob = new Character("bob");
  ICharacter *me = new Character("me");

  int i = 0;
  int j = 0;

  // equip up to limit
  bob->equip(ices[i++]);
  bob->equip(ices[i++]);
  bob->equip(ices[i++]);
  bob->equip(ices[i++]);

  // equip overflow (should be ignored)
  bob->equip(cures[j]);

  // unequip test
  AMateria *stash = bob->getMateria(0);
  bob->unequip(0);

  // equip & use
  me->equip(cures[j++]);
  me->use(0, *bob);

  // use boundary (empty slot & out-of-range)
  for (int k = 0; k < 5; k++)
    bob->use(k, *me);

  /* ============================================================
   * 5. Manual cleanup (ownership test)
   * ============================================================ */
  for (; i < 10; i++)
    delete ices[i];

  for (; j < 10; j++)
    delete cures[j];

  delete stash;
  delete overflow;
  delete bob;
  delete me;
  delete source;

  return 0;
}
