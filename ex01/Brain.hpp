#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <iomanip>

class Brain
{
    protected:
        std::string ideas_[100];
    public:
        Brain(void);
        Brain(Brain const &other);
        Brain &operator=(Brain const &other);
        ~Brain(void);
};

#endif
