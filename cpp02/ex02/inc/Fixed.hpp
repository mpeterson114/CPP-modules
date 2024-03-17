/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:02:47 by mpeterso          #+#    #+#             */
/*   Updated: 2024/03/17 17:02:48 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _fixedPointVal;
        static const int _fracBits = 8;

    public:
        Fixed(void);
        Fixed(Fixed const &copy);
        Fixed(int const value);
        Fixed(float const value);
        Fixed &operator=(Fixed const &copy);
         ~Fixed(void);

        /* Comparison operators */
        bool operator>(Fixed const &value) const;
        bool operator<(Fixed const &value) const;
        bool operator>=(Fixed const &value) const;
        bool operator<=(Fixed const &value) const;
        bool operator==(Fixed const &value) const;
        bool operator!=(Fixed const &value) const;

        /* Arithmetic operators */
        Fixed operator+(Fixed const &value) const;
        Fixed operator-(Fixed const &value) const;
        Fixed operator*(Fixed const &value) const;
        Fixed operator/(Fixed const &value) const;

        /* Increment/Decrement operators */
        Fixed &operator++(void);  /* pre-increment */
        Fixed operator++(int);    /* post-increment */
        Fixed &operator--(void);  /* pre-decrement */
        Fixed operator--(int);    /* post-decrement */

        /* Static member functions */
        static Fixed &min(Fixed &x, Fixed &y);
        static const Fixed &min(Fixed const &x, Fixed const &y);
        static Fixed &max (Fixed &x, Fixed &y);
        static const Fixed &max(Fixed const &x, Fixed const &y);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream  &operator<<(std::ostream &str, Fixed const &fixed_nbr);


#endif