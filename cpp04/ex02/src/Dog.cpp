/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:02:55 by mpeterso          #+#    #+#             */
/*   Updated: 2024/08/25 17:10:06 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal(), _brain(new Brain())
{
    std::cout << "Dog constructor called" << std::endl;
    this->_type = "Dog";
}

Dog::Dog(Dog const &copy) : AAnimal(copy), _brain(NULL)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_type = copy._type;
    *this = copy;
}

Dog &Dog::operator=(Dog const &copy)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &copy) 
    {
        this->_type = copy._type;
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*copy._brain);
    }   
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
}

Brain &Dog::getBrain(void) const
{
    return (*this->_brain);
}

void Dog::setBrain(Brain const &brain)
{
    *this->_brain = brain;
}

void Dog::makeSound() const
{
    std::cout << "\033[34m * WOOF WOOF * \033[0m" << std::endl;
}
