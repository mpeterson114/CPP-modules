#include "Fixed.hpp"

/****************************************************************/
/*              CONSTRUCTORS & DESTRUCTORS                      */
/****************************************************************/

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

/****************************************************************/
/*                   COMPARISON OPERATORS                       */
/****************************************************************/

bool Fixed::operator>(const Fixed &value) const
{
    return this->_fixedPointVal > value._fixedPointVal;
}

bool Fixed::operator<(Fixed const &value) const
{
    return this->_fixedPointVal < value._fixedPointVal;
}

bool Fixed::operator>=(Fixed const &value) const
{
    return this->_fixedPointVal >= value._fixedPointVal;
}

bool Fixed::operator<=(Fixed const &value) const
{
    return this->_fixedPointVal <= value._fixedPointVal;
}

bool Fixed::operator==(Fixed const &value) const
{
    return this->_fixedPointVal == value._fixedPointVal;
}

bool Fixed::operator!=(Fixed const &value) const
{
    return this->_fixedPointVal != value._fixedPointVal;
}

/****************************************************************/
/*                   ARITHMETIC OPERATORS                       */
/****************************************************************/

Fixed Fixed::operator+(Fixed const &value) const
{
    return Fixed(this->toFloat() + value.toFloat());
}

Fixed Fixed::operator-(Fixed const &value) const
{
    return Fixed(this->toFloat() - value.toFloat());
}

Fixed Fixed::operator*(Fixed const &value) const
{
    return Fixed(this->toFloat() * value.toFloat());
}

Fixed Fixed::operator/(Fixed const &value) const
{
    return Fixed(this->toFloat() / value.toFloat());
}

/****************************************************************/
/*                  INCREMENT/DECREMENT OPERATORS               */
/****************************************************************/

Fixed &Fixed::operator++(void)              // pre-incrementation
{
    this->_fixedPointVal++;
    return (*this);
}

Fixed Fixed::operator++(int)              // post-incrementation
{
    Fixed tmp(*this);

    ++(*this);
    return (tmp);
}

Fixed &Fixed::operator--(void)              // pre-decrementation
{
    this->_fixedPointVal--;
    return (*this);
}

Fixed Fixed::operator--(int)              // post-decrementation
{
    Fixed tmp(*this);

    --(*this);
    return (tmp);
}

/****************************************************************/
/*                  MIN/MAX STATIC FUNCTIONS                    */
/****************************************************************/

Fixed &Fixed::min(Fixed &x, Fixed &y)
{
    if (x.getRawBits() < y.getRawBits())
        return (x);
    return (y);
}

const Fixed &Fixed::min(Fixed const &x, Fixed const &y)
{
    if (x.getRawBits() < y.getRawBits())
        return (x);
    return (y);
}

Fixed &Fixed::max(Fixed &x, Fixed &y)
{
    if (x.getRawBits() > y.getRawBits())
        return (x);
    return (y);
}

const Fixed &Fixed::max(Fixed const &x, Fixed const &y)
{
    if (x.getRawBits() > y.getRawBits())
        return (x);
    return (y);
}

/****************************************************************/
/*                   GETTERS & SETTERS                          */
/****************************************************************/

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointVal);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointVal = raw;
}

/****************************************************************/
/*                OTHER PUBLIC FUNCTIONS                        */
/****************************************************************/

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