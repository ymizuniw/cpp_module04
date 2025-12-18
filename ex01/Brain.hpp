#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
private:
  std::string ideas_[100];

public:
  Brain(void);
  Brain(Brain const &other);
  Brain &operator=(Brain const &other);
  ~Brain(void);
#ifdef DEBUG
  std::string getIdea(size_t i);
#endif
};

#endif
