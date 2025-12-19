#include "includes/MateriaSource.hpp"
#include "includes/AMateria.hpp"
#include <iostream>

// private:
// AMateria *materia_src_[4];

// public:
// MateriaSource(void);
// MateriaSource(MateriaSource const &other);
// MateriaSource &operator=(MateriaSource const &other);
// ~MateriaSource(void);
// void learnMateria(AMateria *);
// AMateria *createMateria(std::string const &type);

MateriaSource::MateriaSource(void) {
  std::cout << "MateriaSource default construcotr called" << std::endl;
  for (int i = 0; i < 4; i++)
    materia_src_[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other) {
  std::cout << "MateriaSource copy construcotr called" << std::endl;
  for (int i = 0; i < 4; i++)
    materia_src_[i] = other.materia_src_[i]->clone();
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
  if (this == &other)
    return *this;
  for (int i = 0; i < 4; i++) {
    if (materia_src_[i] != NULL)
      delete materia_src_[i];
  }
  for (int i = 0; i < 4; i++)
    materia_src_[i] = other.materia_src_[i]->clone();
  return (*this);
}

MateriaSource::~MateriaSource(void) {
  std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m) {
  for (int i = 0; i < 4; i++) {
    if (materia_src_[i] == NULL) {
      materia_src_[i] = m;
      break;
    }
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < 4; i++) {
    if (materia_src_[i] && materia_src_[i]->getType() == type) {
      return (materia_src_[i]->clone());
    }
  }
  return (0);
}
