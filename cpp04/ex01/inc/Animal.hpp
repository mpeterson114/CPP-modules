/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:02:42 by mpeterso          #+#    #+#             */
/*   Updated: 2024/08/15 12:25:04 by mpeterso         ###   ########.fr       */
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

    /* pure virtual function ('=0'), no implementation in Animal.c. Makes Animal an abstract class
    * that cannot be instantiated directly, can't create objects of this class. Only for use as a
    * base class.
    * Also requires any derived classes to explicitly implement their own versions of this function
    */
        virtual Brain &getBrain(void) const = 0;  
        std::string const &getType(void) const;
        virtual void makeSound() const;
    /* allows derived classes to optionally override makeSound() function from Animal class, 
    *  can still be instantiated with default behavior. Animal class could still be instantiated
    *  if only had this virtual function (and not the pure virtual getBrain() function)*/
};

#endif