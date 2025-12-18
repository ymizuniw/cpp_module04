#include "IMateriaSource.hpp"
#include <iostream>

IMateriaSource::IMateriaSource(void) {
  std::cout << "IMateriaSource default construcotr called" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const &other) { (void)other; }

IMateriaSource &IMateriaSource::operator=(IMateriaSource const &other) {
  if (this != &other)
    *this = other;
  return *this;
}

IMateriaSource::~IMateriaSource(void) {
  std::cout << "IMateriaSource destrucotr called" << std::endl;
}
