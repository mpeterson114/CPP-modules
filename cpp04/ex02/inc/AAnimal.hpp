/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:02:42 by mpeterso          #+#    #+#             */
/*   Updated: 2024/08/18 11:44:20 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
    protected:
        std::string _type;
    
    public:
        AAnimal();
        AAnimal(std::string const &type);
        AAnimal(AAnimal const &copy);
        AAnimal &operator=(AAnimal const &copy);
        virtual ~AAnimal();

        std::string const &getType(void) const;
        virtual void makeSound() const = 0;
    /* pure virtual function ('=0'), no implementation in Animal.c. Makes Animal an abstract class
    * that cannot be instantiated directly, can't create objects of this class. Only for use as a
    * base class.
    * Also requires any derived classes to explicitly implement their own versions of this function
    */
};

#endif
