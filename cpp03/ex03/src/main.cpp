/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:00:27 by mpeterso          #+#    #+#             */
/*   Updated: 2024/03/17 17:00:29 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) 
{
    std::cout << "----------Constructors------------" << std::endl;
    std::cout << std::endl;
    std::string	fragTrapName = "A";
	std::string scavTrapName = "B";

	FragTrap	fragTrap(fragTrapName);
	ScavTrap	scavTrap(scavTrapName);
    std::cout << std::endl;

    std::cout << "-------------Battle---------------" << std::endl;
    std::cout << std::endl;
    fragTrap.highFivesGuys();
    scavTrap.guardGate();
    fragTrap.attack(scavTrapName);
    scavTrap.takeDamage(30);
    fragTrap.attack(scavTrapName);
    scavTrap.takeDamage(30);
    fragTrap.attack(scavTrapName);
    scavTrap.takeDamage(30);
    fragTrap.attack(scavTrapName);
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