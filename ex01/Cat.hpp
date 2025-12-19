#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
  private:
	Brain *brain_;

  public:
	Cat(void);
	Cat(Cat const &other);
	Cat &operator=(Cat const &other);
	~Cat(void);
	virtual void makeSound(void) const;
# ifdef DEBUG
	void print_ideas(void);
# endif
};

#endif
