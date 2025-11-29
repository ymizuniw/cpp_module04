#include "Dog.hpp"

Dog::Dog(void) : Animal(), brain_(new Brain())
{
    type_="Dog";
    std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(Dog const &other) : Animal(), brain_(new Brain())
{
    if (this!=&other)
    {
        type_="Dog";
        Animal::operator=(other);
    }
    std::cout << "Dog copy-constructor called." << std::endl;
}

Dog const &Dog::operator=(Dog const &other)
{
    if (this!=&other)
    {
        delete (brain_);
        brain_ = new Brain(*other.brain_);
        Animal::operator=(other);
    }
    return (*this);
}

Dog::~Dog(void)
{
    delete (brain_);
    std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "bawow" << std::endl;
}
