/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:01:35 by mpeterso          #+#    #+#             */
/*   Updated: 2024/04/05 12:10:17 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) 
{
    std::cout << "----------Constructors------------" << std::endl;
    std::cout << std::endl;

	ClapTrap	a("CT-A");
	ScavTrap	b("ST-B");
    ScavTrap    c("ST-C");
    std::cout << std::endl;

    std::cout << "-------------Battle---------------" << std::endl;
    std::cout << std::endl;
    b.guardGate();
    c.guardGate();
    b.attack("CT-A");
    a.takeDamage(20);
    a.attack("ST-B");
    a.beRepaired(10);
    std::cout << std::endl;
    b.attack("ST-C");
    c.takeDamage(20);
    b.attack("ST-C");
    c.takeDamage(20);
    c.beRepaired(2);
    for (int i = 0; i < 5; i++)
    {
        b.attack("ST-C");
        c.takeDamage(20);
    }
    std::cout << std::endl;
    c.attack("ST-B");
    c.beRepaired(2);
    c.guardGate();
    std::cout << std::endl;
    std::cout << "----------Destructors------------" << std::endl;
    std::cout << std::endl;
    return (0);
}