#include "Fixed.hpp"

Fixed::Fixed(void): _fixedPointVal(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(int const value): _fixedPointVal(value << _fracBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value)
{
    
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

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointVal);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointVal = raw;
}