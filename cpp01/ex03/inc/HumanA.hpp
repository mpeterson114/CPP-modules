/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:06:49 by mpeterso          #+#    #+#             */
/*   Updated: 2024/03/14 15:16:29 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA 
{
    private:
        std::string _name;
        Weapon &_weapon;
    
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);

        void attack(void) const;
};

#endif