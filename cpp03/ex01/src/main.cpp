/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:01:35 by mpeterso          #+#    #+#             */
/*   Updated: 2024/04/04 16:15:18 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) 
{
    std::cout << "----------Constructors------------" << std::endl;
    std::cout << std::endl;
    // std::string	clapTrapName = "A";
	// std::string scavTrapName1 = "B";
    // std::string scavTrapName2 = "C";

	ClapTrap	a("CLPTRP-A");
	ScavTrap	b("SCVTRP-B");
    ScavTrap    c("SCVTRP-C");
    std::cout << std::endl;

    std::cout << "-------------Battle---------------" << std::endl;
    std::cout << std::endl;
    b.guardGate();
    c.guardGate();
    b.attack("CLPTRP-A");
    a.takeDamage(20);
    a.attack("SCVTRP-B");
    a.beRepaired(10);
    std::cout << std::endl;
    b.attack("SCVTRP-C");
    c.takeDamage(20);
    b.attack("SCVTRP-C");
    c.takeDamage(20);
    c.beRepaired(2);
    for (int i = 0; i < 5; i++)
    {
        b.attack("SCVTRP-C");
        c.takeDamage(20);
    }
    std::cout << std::endl;
    c.attack("SCVTRP-B");
    c.beRepaired(2);
    c.guardGate();
    // std::cout << "retaliation..." << std::endl;
    // for (int i = 0; i < 9; i++)
    // {
    //     clapTrap.attack(scavTrapName);
    //     scavTrap.takeDamage(0);
    // }
    // clapTrap.attack(scavTrapName);
    std::cout << std::endl;
    std::cout << "----------Destructors------------" << std::endl;
    std::cout << std::endl;
    return (0);
}