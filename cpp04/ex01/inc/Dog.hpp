/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:02:32 by mpeterso          #+#    #+#             */
/*   Updated: 2024/08/06 11:11:48 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
    private:
        Brain *_brain;
        
    public:
        Dog();
        Dog(Dog const &copy);
        Dog &operator=(Dog const &copy);
        ~Dog();

        Brain *getBrain(void) const;
        void makeSound() const;
};

#endif