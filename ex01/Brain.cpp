#include "Brain.hpp"
#include "print_utils.hpp"

Brain::Brain(void)
{
    bzero(ideas_, 100);
    print_msg("Brain construcotr called.");
}

Brain::Brain(const Brain &other)
{
    memcpy(ideas_, other.ideas_, sizeof(ideas_)/sizeof(ideas_[0]));     
    print_msg("Brain copy-construcotr called.");
}

Brain &Brain::operator=(const Brain &other)
{
    if (this!=&other)
        memcpy(ideas_, other.ideas_, 100);
    return (*this);
}

Brain::~Brain(void)
{
    print_msg("Brain destructor is called.");
}
