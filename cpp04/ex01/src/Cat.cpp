/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:02:52 by mpeterso          #+#    #+#             */
/*   Updated: 2024/08/06 11:58:28 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain())
{
    std::cout << "Cat constructor called" << std::endl;
    this->_type = "Cat";
}

Cat::Cat(Cat const &copy) : Animal(copy), _brain(NULL)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->_type = copy._type;
    *this = copy;
}

Cat &Cat::operator=(Cat const &copy)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*copy._brain);
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain;
}

Brain *Cat::getBrain(void) const
{
    return (this->_brain);
}

void Cat::makeSound() const
{
    std::cout << "\033[34m * meowwwww * \033[0m" << std::endl;
}
