Found multiple issues across the project. Below is a concise, file-by-file summary (only callouts where something is wrong or risky). Click each path to open that file.

General high-level problems

Several header/include cycles and missing null checks can cause crashes or UB.
Many copy/assignment implementations do shallow copies of owning raw pointers (double-delete / leaks).
Use of memcpy/bzero with std::string (non-POD) is undefined behaviour.
Minor typos in log messages and inconsistent include-guard names (not fatal but messy).
Key symbols I reference:

AMateria::AMateria() (file)
MateriaSource::createMateria (file)
MateriaSource::learnMateria (file)
Character::equip (file)
Character::unequip (file)
Character::Character(const Character&) (file)
Brain::Brain() / operator=` (file)
Problems by directory (only issues called out)

ex03 (Materia / Character)

AMateria.hpp
Declares AMateria(void) (default ctor) but no implementation in AMateria.cpp. Link: AMateria.cpp
Circular include: ICharacter.hpp also includes "AMateria.hpp" — keep only a forward declaration in one header to avoid include cycles. See: ICharacter.hpp
ICharacter.hpp
It includes "AMateria.hpp" and then forward-declares AMateria; remove the #include and only forward-declare to break cycle.
MateriaSource.cpp
createMateria() dereferences materia_src_[i] without nullptr check -> crash if empty slots. (See MateriaSource::createMateria)
copy ctor / operator= perform shallow copy of materia_src_ pointers; destructor deletes them -> double-delete when copies exist. Should deep-copy (clone) or follow rule-of-three/five semantics properly. (See MateriaSource::learnMateria)
learnMateria clones the passed materia; this is OK, but your copy semantics need to match ownership model.
Character.cpp
Copy ctor / operator= call other.slot_[i]->clone() without checking other.slot_[i] for nullptr -> crash. (See Character::Character(const Character&))
equip(AMateria *m) clones m and stores the clone, but caller often passes a freshly allocated pointer (e.g., createMateria returns a new object). You clone again and never delete the original passed pointer -> memory leak and confusing ownership. Either: store the passed pointer (and let caller not delete), or document/standardize ownership (and avoid double-clone).
unequip(int) deletes the slot and does not set slot_[idx] = nullptr -> potential use-after-free. Also, per many subject specs, unequip should NOT delete the materia (should only drop it). Decide and implement consistent behavior.
use() is fine but relies on slot_ being valid.
[ex03/Cure.cpp], [ex03/Ice.cpp]
copy-ctors call AMateria(other.type_) — OK, but ensure AMateria copy ctor semantics are correct.
Other small items:
createMateria returns 0 instead of nullptr (style).
Several print messages have typos (e.g., "copy-construcotr").
ex02 / ex01 / ex00 (Animals, Brain, WrongAnimal)

Brain.cpp and Brain.cpp
Using bzero and memcpy on std::string array is undefined behaviour. You must copy strings element-wise (e.g., loop assign or std::copy). Current code may compile but is UB.
memcpy sizes are inconsistent/wrong: e.g., memcpy(ideas_, other.ideas_, sizeof(ideas_)/sizeof(ideas_[0])) – that expression yields count of elements, not bytes.
Suggest implementing:
Brain::Brain(): initialize array with default-constructed std::string (no bzero).
Brain::operator= and copy ctor use std::copy or loop to assign strings.
[ex02/Dog.hpp] / [ex02/Dog.cpp]
operator= return type is Dog const & (legal but unusual); consistency is OK but prefer Dog &.
[ex02/AbstractAnimal.hpp] / [ex02/WrongAnimal.hpp]
In [ex02/WrongAnimal.hpp] the include-guard macro name is WRONG_AbstractAnimal_HPP (confusing, misnamed).
[ex02/Makefile]
Duplicate pattern rules for %.o (both %.c and %.cpp) are OK but redundant.
ex01 / ex00 (Animals)

Mostly OK; same remarks about copy semantics for classes owning Brain* (use deep copy, current code does deep copy in many places but check consistency).
[ex00/Makefile], [ex01/Makefile]
Fine but ensure correct SRCS lists per exercise.
Misc / small style

Multiple print_utils.hpp across exercises share the same include-guard macro PRINT_UTILS_HPP — if you ever compile files from different exercises together this will cause one header to be ignored; safe per-exercise but consider unique guards or a shared include path.
Use nullptr instead of 0 when returning null pointer.
Prefer initializing std::string with default or use std::array/std::vector for safer semantics.
Ensure all declared functions have definitions (e.g., AMateria default ctor).
All files (click to open)

Animal.cpp
Animal.hpp
Cat.cpp
Cat.hpp
Dog.cpp
Dog.hpp
Makefile
WrongAnimal.cpp
WrongAnimal.hpp
WrongCat.cpp
WrongCat.hpp
main.cpp
Animal.cpp
Animal.hpp
Cat.cpp
Cat.hpp
Dog.cpp
Dog.hpp
Brain.cpp
Brain.hpp
Makefile
WrongAnimal.cpp
WrongAnimal.hpp
WrongCat.cpp
WrongCat.hpp
main.cpp
print_utils.cpp
print_utils.hpp
AbstractAnimal.cpp
AbstractAnimal.hpp
Cat.cpp
Cat.hpp
Dog.cpp
Dog.hpp
Brain.cpp
Brain.hpp
Makefile
print_utils.cpp
print_utils.hpp
WrongAnimal.cpp
WrongAnimal.hpp
WrongCat.cpp
WrongCat.hpp
main.cpp
AMateria.cpp
AMateria.hpp
Cure.hpp
Cure.cpp
Character.hpp
Character.cpp
ICharacter.hpp
IMateriaSource.hpp
MateriaSource.hpp
MateriaSource.cpp
Ice.hpp
Ice.cpp
main.cpp
Makefile
print_utils.cpp
print_utils.hpp
settings.json
If you want, I can provide minimal patch examples for:

fixing the AMateria/ICharacter include-cycle,
fixing Character::equip/unequip ownership and null checks,
making Brain copy/assign safe,
fixing MateriaSource deep-copy semantics.