#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
  AMateria *materia_src_[4];

public:
  MateriaSource(void);
  MateriaSource(MateriaSource const &other);
  MateriaSource &operator=(MateriaSource const &other);
  ~MateriaSource(void);
  void learnMateria(AMateria *);
  AMateria *createMateria(std::string const &type);
};

#endif
