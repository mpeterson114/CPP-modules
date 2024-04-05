/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:00:55 by mpeterso          #+#    #+#             */
/*   Updated: 2024/04/05 14:04:07 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) 
{
    std::cout << "----------Constructors------------" << std::endl;
    std::cout << std::endl;

	FragTrap	fragTrap1("FT-A");
    FragTrap	fragTrap2("FTRP-B");
	ScavTrap	scavTrap("STRP-C");
    std::cout << std::endl;

    std::cout << "-------------Battle---------------" << std::endl;
    std::cout << std::endl;
    fragTrap1.highFivesGuys();
    fragTrap2.highFivesGuys();
    scavTrap.guardGate();
    fragTrap1.attack("STRP-C");
    scavTrap.takeDamage(30);
    fragTrap1.attack("STRP-C");
    scavTrap.takeDamage(30);
    fragTrap1.attack("STRP-C");
    scavTrap.takeDamage(30);
    fragTrap1.attack("STRP-C");
    scavTrap.takeDamage(30);
    std::cout << std::endl;
    scavTrap.guardGate();
    scavTrap.beRepaired(10);
    std::cout << std::endl;
    for (int i = 5; i > 0; i--)
    {
        fragTrap2.attack("FT-A");
        fragTrap1.takeDamage(30);
    }
    std::cout << std::endl;
    fragTrap1.highFivesGuys();
    fragTrap1.beRepaired(10);
    std::cout << std::endl;
    std::cout << "----------Destructors------------" << std::endl;
    std::cout << std::endl;
    return (0);
}