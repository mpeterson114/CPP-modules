/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:07:04 by mpeterso          #+#    #+#             */
/*   Updated: 2024/03/07 10:07:05 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB(void) {}

void HumanB::attack(void) const 
{
    if (this->_weapon)
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " has no weapon, unable to attack." << std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
    if (newWeapon.getType().empty())
    {
        std::cerr << "Error: New weapon must have a type" << std::endl;
        return ;
    }
    this->_weapon = &newWeapon;
}