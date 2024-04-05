/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:02:54 by mpeterso          #+#    #+#             */
/*   Updated: 2024/04/05 13:53:57 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) / Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << a-- << std::endl;
    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << ++a << std::endl;
    
    std::cout << b << std::endl;

    std::cout << a + b << std::endl;
    std::cout << b - a << std::endl;

    std::cout << "Larger number is: " << Fixed::max( a, b ) << std::endl;
    std::cout << "Smaller number is: " << Fixed::min( a, b ) << std::endl;
    return 0;
}