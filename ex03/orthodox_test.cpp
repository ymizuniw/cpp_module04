#include "includes/AMateria.hpp"
#include "includes/Character.hpp"
#include "includes/Cure.hpp"
#include "includes/ICharacter.hpp"
#include "includes/Ice.hpp"
#include "includes/MateriaSource.hpp"
#include <iostream>

int main(void) {

  /* ============================================================
   * MateriaSource : ctor / copy / assignment
   * ============================================================ */
  std::cout << "============ MateriaSource ===========" << std::endl;

  std::cout << "[Default Ctor] ";
  MateriaSource src;

  std::cout << "[Copy Ctor] ";
  MateriaSource src_cp(src);

  std::cout << "[Learn Materia]" << std::endl;
  AMateria *ice = new Ice();
  AMateria *cure = new Cure();
  src.learnMateria(ice);
  src.learnMateria(cure);

  std::cout << "[Copy Assignment]" << std::endl;
  src_cp = src;

  /* ============================================================
   * createMateria clone consistency
   * ============================================================ */
  std::cout << "========== createMateria ==========" << std::endl;

  AMateria *ice1 = src.createMateria("ice");
  AMateria *cure1 = src.createMateria("cure");
  AMateria *ice2 = src_cp.createMateria("ice");
  AMateria *cure2 = src_cp.createMateria("cure");

  if (ice1->getType() == ice2->getType() &&
      cure1->getType() == cure2->getType())
    std::cout << "[Type Corresponds]" << std::endl;
  else
    std::cout << "[Type Mismatch]" << std::endl;

  /* ============================================================
   * Character : ctor / copy semantics
   * ============================================================ */
  std::cout << "============= Character =============" << std::endl;

  std::cout << "[Default Ctor] ";
  Character ch1;

  std::cout << "[Param Ctor] ";
  Character ch2("Tom");

  std::cout << "[Copy Ctor] ";
  Character ch3(ch1);
  if (ch3.getName() == ch1.getName())
    std::cout << "[Name Copied]" << std::endl;
  else
    std::cout << "[Name Mismatch]" << std::endl;

  /* ============================================================
   * equip / assignment deep copy check
   * ============================================================ */
  std::cout << "========== Copy Assignment ==========" << std::endl;

  Character ch4("Cathy");
  ch4.equip(ice1);
  ch4.equip(cure1);

  ch1 = ch4;

  std::cout << "[Source : " << ch4.getName() << "]" << std::endl;
  ch4.use(0, ch2);
  ch4.use(1, ch2);

  std::cout << "[Copied : " << ch1.getName() << "]" << std::endl;
  ch1.use(0, ch2);
  ch1.use(1, ch2);

  /* ============================================================
   * Cleanup
   * ============================================================ */
  delete ice2;
  delete cure2;

  return 0;
}
