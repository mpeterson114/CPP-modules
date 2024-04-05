/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:00:27 by mpeterso          #+#    #+#             */
/*   Updated: 2024/04/05 17:52:36 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) 
{
    std::cout << "----------Constructors------------" << std::endl;
    std::cout << std::endl;
    std::string clapTrapName = "CLAPPY";
    std::string scavTrapName = "SCAVVY";
    std::string diamondTrapName = "DIAMOND";
	
    ClapTrap    clapTrap(clapTrapName);
	ScavTrap	scavTrap(scavTrapName);
    DiamondTrap diamondTrap(diamondTrapName);
    std::cout << std::endl;

    std::cout << "-------------Battle---------------" << std::endl;
    std::cout << std::endl;
    diamondTrap.whoAmI();
    clapTrap.attack(diamondTrapName);
    diamondTrap.takeDamage(0);
    scavTrap.attack(diamondTrapName);
    diamondTrap.takeDamage(20);
    diamondTrap.beRepaired(10);
    diamondTrap.attack(scavTrapName);
    scavTrap.takeDamage(30);
    diamondTrap.guardGate();
    diamondTrap.highFivesGuys();
    std::cout << std::endl;
    for (int i = 6; i > 0; i--)
    {
        scavTrap.attack(diamondTrapName);
        diamondTrap.takeDamage(20);
    }
    std::cout << std::endl;
    std::cout << "----------Destructors------------" << std::endl;
    std::cout << std::endl;
    return (0);
}