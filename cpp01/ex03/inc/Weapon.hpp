/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:06:55 by mpeterso          #+#    #+#             */
/*   Updated: 2024/03/07 10:06:56 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon{
    private:
        std::string _type;
    
    public:
        Weapon(std::string type);
        ~Weapon(void);

        const std::string &getType(void) const;
        void setType(const std::string &newType);
};

#endif