#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void): IMateriaSource() {
  for (size_t i = 0; i < 4; i++)
    materia_src_[i] = NULL;
  std::cout << "MateriaSource constructor called." << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &other): IMateriaSource(other) {
  for (size_t i = 0; i < 4; i++)
    materia_src_[i] = other.materia_src_[i];
  std::cout << "MateriaSource constructor called." << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
  if (this != &other) {
    for (size_t i = 0; i < 4; i++)
      materia_src_[i] = other.materia_src_[i];
  }
  return (*this);
}

MateriaSource::~MateriaSource(void) {
  for (size_t i = 0; i < 4; i++) {
    if (materia_src_[i] != NULL)
      delete (materia_src_[i]);
  }
  std::cout << "MateriaSource destructor called." << std::endl;
}

void MateriaSource::learnMateria(AMateria *materia) {
  size_t i = 0;
  for (; i < 4; i++) {
    if (materia_src_[i] == NULL) {
      materia_src_[i] = materia->clone();
      break;
    }
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (size_t i = 0; i < 4; i++) {
    if (materia_src_[i]->getType() == type) {
      AMateria *cp_materia = materia_src_[i]->clone();
      return (cp_materia);
    }
  }
  return (0);
}
