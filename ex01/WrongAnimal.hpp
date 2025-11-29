#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

// To ensure you understood how it works, implement a WrongCat class that inherits
// from a WrongAnimal class. If you replace the Animal and the Cat by the wrong ones
// in the code above, the WrongCat should output the WrongAnimal sound.

class WrongAnimal
{
    protected:
        std::string type_;
    public:
        WrongAnimal(void);
        WrongAnimal(WrongAnimal const &other);
        WrongAnimal &operator=(WrongAnimal const &other);
        virtual ~WrongAnimal(void);
        void makeSound(void) const;//not virtual.
        std::string getType(void) const;
};

#endif
