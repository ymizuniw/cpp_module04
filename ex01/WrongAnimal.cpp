#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    type_="WrongAnimal";
    std::cout << "WrongAnimal constructed." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) : type_(other.type_)
{
    std::cout << "WrongAnimal copy-constructor called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
    if (this!=&other)
        type_=other.type_;
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called." << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (type_);
}
