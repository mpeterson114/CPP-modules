/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:01:49 by mpeterso          #+#    #+#             */
/*   Updated: 2024/03/17 17:01:50 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) 
{
    std::cout << "----------Constructors------------" << std::endl;
    std::cout << std::endl;
    ClapTrap a = ClapTrap("A");
    ClapTrap b = ClapTrap("B");
    std::cout << std::endl;

    std::cout << "--------------Tests---------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Attack/Damage tests..." << std::endl;
    for (int i = 0; i < 9; i++)
    {
        a.attack("B");
        b.takeDamage(0);
    }
    a.attack("B");
    a.attack("B");
    a.attack("B");
    std::cout << std::endl;
    std::cout << "Damage/Repair tests..." << std::endl; 
    for (int i = 0; i <= 10; i++)
    {
        b.takeDamage(3);
        b.beRepaired(3);
    }
    b.beRepaired(1);
    std::cout << std::endl;
    std::cout << "----------Destructors------------" << std::endl;
    std::cout << std::endl;
    return (0);
}