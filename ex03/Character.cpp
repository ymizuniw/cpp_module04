#include "includes/Character.hpp"
#include "includes/AMateria.hpp"
#include <iostream>

// private:
//   std::string name_;
//   AMateria *slot_[4];//init empty

// public:
//   Character(void);
//   Character(std::string const name);
//   Character(Character const &other);
//   Character &operator=(Character const &other);

Character::Character(void) : name_("Character_default_name") {
  std::cout << "Character default constructor called" << std::endl;
  for (int i = 0; i < 4; i++)
    slot_[i] = NULL;
}

Character::Character(std::string const name) : name_(name) {
  std::cout << "Character parameterized constructor called" << std::endl;
  for (int i = 0; i < 4; i++)
    slot_[i] = NULL;
}

Character::Character(Character const &other) : name_(other.name_) {
  std::cout << "Character copy constructor called" << std::endl;
  for (int i = 0; i < 4; i++)
    slot_[i] = other.slot_[i]->clone(); // replicate and hold.
}

Character &Character::operator=(Character const &other) {
  if (this == &other)
    return (*this);
  name_ = other.name_;
  for (int i = 0; i < 4; i++) {
    if (slot_[i] != NULL)
      delete slot_[i];
  }
  for (int i = 0; i < 4; i++)
    slot_[i] = other.slot_[i]->clone(); // replicate and hold.
  return (*this);
}

//   //Based on ICharacter
//   ~Character(void);
//   std::string const &getName(void) const;
//   void equip(AMateria *m);
//   void unequip(int idx);
//   void use(int idx, ICharacter &target);

Character::~Character(void) {
  std::cout << "Character destructor called" << std::endl;
}

std::string const &Character::getName(void) const { return (name_); }

void Character::equip(AMateria *m) {
  for (int i = 0; i < 4; i++) {
    if (slot_[i] == NULL) {
      slot_[i] = m; // this is external pointer!
      break;
    }
  }
}

// ensure that the pointer of slot[idx] content is held by caller before unequip
void Character::unequip(int idx) {
  if (slot_[idx] != NULL)
    slot_[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
  if (slot_[idx] != NULL) {
    slot_[idx]->use(target);
  }
}
