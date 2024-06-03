#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog();
        Dog(std::string type);
        Dog(Dog const &copy);
        Dog &operator=(Dog const &copy);
        ~Dog();

        void makeSound();
};

#endif