/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:02:42 by mpeterso          #+#    #+#             */
/*   Updated: 2024/06/06 13:52:13 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal {
    protected:
        std::string _type;
    
    public:
        Animal();
        Animal(std::string const &type);
        Animal(Animal const &copy);
        Animal &operator=(Animal const &copy);
        virtual ~Animal();

        std::string const &getType(void) const;
        virtual void makeSound() const;
};

#endif