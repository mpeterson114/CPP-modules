#include "Animal.hpp"

Animal::Animal() :
{
    std::cout << "Animal default constructor called" << std::endl;
}



void Animal::makeSound()
{
    std::cout << this->_type << std::endl;
}