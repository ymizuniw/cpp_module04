#include "Cure.hpp"
#include "print_utils.hpp"

Cure::Cure(void): AMateria("cure")
{
    print_msg("Cure constructor called.");
}

Cure::Cure(Cure const &other): AMateria(other.type_)
{
    print_msg("Cure copy-constructor called.");
}

Cure &Cure::operator=(Cure const &other)
{
    if (this!=&other)
    {
        type_=other.type_;
    }
    return (*this);
}

Cure::~Cure(void)
{
    print_msg("Cure destructor called.");
}

AMateria *Cure::clone(void) const
{
    AMateria *cure_cp = new Cure(*this);
    return (cure_cp);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() 
            << "'s wounds *" <<std::endl;
}
