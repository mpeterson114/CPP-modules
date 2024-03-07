/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:06:52 by mpeterso          #+#    #+#             */
/*   Updated: 2024/03/07 10:06:53 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB 
{
    private:
        std::string _name;
        Weapon *_weapon;
    
    public:
        HumanB(std::string name);
        ~HumanB(void);

        void attack(void) const;
        void setWeapon(Weapon &newWeapon);
};

#endif