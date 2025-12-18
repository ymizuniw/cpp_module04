#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice(void);
        Ice(Ice const &other);
        Ice &operator=(Ice const &other);
        ~Ice(void);
        AMateria *clone(void) const;
        void use(ICharacter &target);
};

#endif
