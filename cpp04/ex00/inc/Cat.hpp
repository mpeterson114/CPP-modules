#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat();
        Cat(std::string type);
        Cat(Cat const &copy);
        Cat &operator=(Cat const &copy);
        ~Cat();

        void makeSound();
};

#endif