/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:02:42 by mpeterso          #+#    #+#             */
/*   Updated: 2024/08/18 11:44:20 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

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
    /* allows derived classes to optionally override makeSound() function from Animal class, 
    *  can still be instantiated with default behavior. Animal class could still be instantiated
    *  if only had this virtual function (vs. if this were a pure virtual function) */
};

#endif