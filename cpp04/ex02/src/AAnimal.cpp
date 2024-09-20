/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:02:35 by mpeterso          #+#    #+#             */
/*   Updated: 2024/08/06 12:00:08 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string const &type) : _type(type)
{
    std::cout << "AAnimal parameterized constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &copy)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = copy;
}

AAnimal &AAnimal::operator=(AAnimal const &copy)
{
    std::cout << "AAnimal assignment operator called" << std::endl;
    if (this != &copy)
        this->_type = copy._type;
    return (*this);
}

AAnimal::~AAnimal()
{
    
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string const &AAnimal::getType() const
{
    return (this->_type);
}
