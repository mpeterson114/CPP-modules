/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:00:55 by mpeterso          #+#    #+#             */
/*   Updated: 2024/04/05 12:43:06 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) 
{
    std::cout << "----------Constructors------------" << std::endl;
    std::cout << std::endl;
    // std::string	fragTrapName = "FTRP-A";
    // std::string	fragTrapName = "FTRP-B";
	// std::string STRP-C = "STRP-C";

	FragTrap	fragTrap("FTRP-A");
    FragTrap	fragTrap("FTRP-B");
	ScavTrap	scavTrap("STRP-C");
    std::cout << std::endl;

    std::cout << "-------------Battle---------------" << std::endl;
    std::cout << std::endl;
    fragTrap.highFivesGuys();
    scavTrap.guardGate();
    fragTrap.attack("STRP-C");
    scavTrap.takeDamage(30);
    fragTrap.attack("STRP-C");
    scavTrap.takeDamage(30);
    fragTrap.attack("STRP-C");
    scavTrap.takeDamage(30);
    fragTrap.attack("STRP-C");
    scavTrap.takeDamage(30);
    scavTrap.guardGate();
    scavTrap.beRepaired(10);
    std::cout << std::endl;
    std::cout << "retaliation..." << std::endl;
    for (int i = 6; i > 0; i--)
    {
        scavTrap.attack(fragTrapName);
        fragTrap.takeDamage(20);
    }
    scavTrap.guardGate();
    fragTrap.highFivesGuys();
    std::cout << std::endl;
    std::cout << "----------Destructors------------" << std::endl;
    std::cout << std::endl;
    return (0);
}