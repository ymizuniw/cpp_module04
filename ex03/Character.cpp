#include "Character.hpp"
#include <iostream>

// private:
//     std::string name_;
//     AMateria *slot_[4];
// public:
//     Character(void);
//     Character(Character const &other);
//     Character &operator=(Character const &other);
//     ~Character(void);
//     std::string const &getName(void) const;
//     void equip(AMateria *m);
//     void unequip(int idx);
//     void use(int idx, ICharacter &target);

Character::Character(void) : name_("default") {
  std::cout << "Character default constructor called" << std::endl;
  for (size_t i = 0; i < 4; i++)
    slot_[i] = nullptr;
}

Character::Character(std::string const name) : name_(name) {
  std::cout << "Character parameterized constructor called" << std::endl;
  for (size_t i = 0; i < 4; i++)
    slot_[i] = nullptr;
}

Character::Character(Character const &other) : name_(other.name_) {
  std::cout << "Character copy constructor called" << std::endl;
  if (this != &other) {
    for (size_t i = 0; i < 4; i++)
      slot_[i] = other.slot_[i]->clone();
  }
}

Character &Character::operator=(Character const &other) {
  if (this != &other) {
    name_ = other.name_;
    for (size_t i = 0; i < 4; i++)
      slot_[i] = other.slot_[i]->clone();
  }
  return (*this);
}

Character::~Character(void) {
  for (size_t i = 0; i < 4; i++) {
    if (slot_[i] != nullptr)
      delete (slot_[i]);
  }
  std::cout << "Character destructor called" << std::endl;
}

std::string const &Character::getName(void) const { return (name_); }

void Character::equip(AMateria *m) {
  for (size_t i = 0; i < 4; i++) {
    if (slot_[i] == nullptr) {
      slot_[i] = m->clone();
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (slot_[idx] != nullptr)
    delete (slot_[idx]);
}

void Character::use(int idx, ICharacter &target) {
  if (slot_[idx] == nullptr)
    return;
  slot_[idx]->use(target);
}
