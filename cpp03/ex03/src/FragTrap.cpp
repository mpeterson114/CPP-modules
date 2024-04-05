/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:00:25 by mpeterso          #+#    #+#             */
/*   Updated: 2024/04/05 17:59:37 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "A FragTrap for " << this->_name << " was constructed" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &src)
{
    ClapTrap::operator=(src);
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap for " << this->_name << " has been destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (this->_hitPoints <= 0)
        std::cout << "FragTrap " << this->_name << " is dead, unable to high-five anyone." << std::endl;
    else
        std::cout << "FragTrap " << this->_name << ": \"HIGH-FIVE GUYS\"" << std::endl;
}