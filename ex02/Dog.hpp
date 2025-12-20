#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
  private:
	Brain *brain_;

  public:
	Dog(void);
	Dog(Dog const &other);
	Dog const &operator=(Dog const &other);
	~Dog(void);
	virtual void makeSound(void) const;
# ifdef DEBUG
	void print_ideas(void) const;
# endif
};

#endif
