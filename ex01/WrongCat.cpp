#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
    type_="WrongCat";
    std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy-constructor called." << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
    if (this!=&other)
        WrongAnimal::operator=(other);
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called." <<  std::endl;
}

void WrongCat::makeSound(void) const//this won't be called.
{
    std::cout << "Wrong cat's meaow!" << std::endl;
}
