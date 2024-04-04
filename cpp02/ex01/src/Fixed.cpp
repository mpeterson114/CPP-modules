/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:03:03 by mpeterso          #+#    #+#             */
/*   Updated: 2024/04/04 15:14:09 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructors & Destructors */
Fixed::Fixed(void): _fixedPointVal(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(int const value) : _fixedPointVal(value << _fracBits) 
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : _fixedPointVal(roundf(value * (1 << _fracBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fixedPointVal = copy.getRawBits();
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

/* Getters & Setters */
int Fixed::getRawBits(void) const
{
    return (this->_fixedPointVal);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointVal = raw;
}

/* Other Public Functions */
float Fixed::toFloat(void) const
{
    return ((float)this->_fixedPointVal / (1 << _fracBits));
}

int Fixed::toInt(void) const
{
    return this->_fixedPointVal >> _fracBits;
}

std::ostream  &operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
    str << fixed_nbr.toFloat();
    return (str);
}