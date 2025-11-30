#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string type_;
    public:
        AMateria(void);
        AMateria(AMateria const &materia);
        AMateria(std::string const &type);
        AMateria            &operator=(AMateria const &materia);
        virtual             ~AMateria(void);
        std::string const   &getType(void) const;
        virtual AMateria    *clone(void) const = 0;
        virtual void        use(ICharacter &target) = 0;
};

#endif

