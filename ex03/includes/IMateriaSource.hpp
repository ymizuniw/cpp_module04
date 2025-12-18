#ifndef IMATERIA_SOURCE_HPP
#define IMATERIA_SOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource {
public:
  IMateriaSource(void);
  IMateriaSource(IMateriaSource const &other);
  IMateriaSource &operator=(IMateriaSource const &other);
  virtual ~IMateriaSource();
  virtual void learnMateria(AMateria *) = 0;
  virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif
