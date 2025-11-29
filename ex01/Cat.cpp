#include "Cat.hpp"

Cat::Cat(void) : Animal(), brain_(new Brain())
{
    type_="Cat";
    std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other), brain_(new Brain())
{
    std::cout << "Cat copy-constructor called." << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
    if (this!=&other)
    {
        delete (brain_);
        brain_ = new Brain(*other.brain_);
        Animal::operator=(other);
    }
    return (*this);
}

Cat::~Cat(void)
{
    delete (brain_);
    std::cout << "Cat destructor called." <<  std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "meaow." << std::endl;
}
