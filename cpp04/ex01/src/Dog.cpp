/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:02:55 by mpeterso          #+#    #+#             */
/*   Updated: 2024/06/03 11:39:23 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog constructor called" << std::endl;
    this->_type = "Dog";
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_type = copy._type;
    *this = copy;
}

Dog &Dog::operator=(Dog const &copy)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &copy)
        this->_type = copy._type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << " * WOOF WOOF * " << std::endl;
}

