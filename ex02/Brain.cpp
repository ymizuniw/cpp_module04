#include "Brain.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

Brain::Brain(void) {
  for (size_t i = 0; i < 100; i++) {
    std::ostringstream oss;
    oss << i;
    std::string num = oss.str();
    ideas_[i] = "idea" + num;
  }
  std::cout << std::setw(9) << std::right << "[Brain] ";
  std::cout << "constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
  for (size_t i = 0; i < 100; i++) {
    ideas_[i] = other.ideas_[i];
  }
  std::cout << std::setw(9) << std::right << "[Brain] ";
  std::cout << "Brain copy-constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
  if (this != &other) {
    for (size_t i = 0; i < 100; i++) {
      ideas_[i] = other.ideas_[i];
    }
  }
  return (*this);
}

Brain::~Brain(void) {
  std::cout << std::setw(9) << std::right << "[Brain] ";
  std::cout << "Brain destructor is called" << std::endl;
}

#ifdef DEBUG
std::string Brain::getIdea(size_t i) {
  if (i >= 100)
    return ("invalid index");
  return (ideas_[i]);
}
#endif
