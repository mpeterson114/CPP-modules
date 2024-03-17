/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:03:00 by mpeterso          #+#    #+#             */
/*   Updated: 2024/03/17 17:03:01 by mpeterso         ###   ########.fr       */
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
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream  &operator<<(std::ostream &str, Fixed const &fixed_nbr);


#endif