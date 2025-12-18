#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
private:
  std::string name_;
  AMateria *slot_[4];

public:
  Character(void);
  Character(std::string const name);
  Character(Character const &other);
  Character &operator=(Character const &other);
  ~Character(void);
  std::string const &getName(void) const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
};

#endif
