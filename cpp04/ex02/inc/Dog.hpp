/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:02:32 by mpeterso          #+#    #+#             */
/*   Updated: 2024/08/18 12:47:09 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
    private:
        Brain *_brain;
        
    public:
        Dog();
        Dog(Dog const &copy);
        Dog &operator=(Dog const &copy);
        ~Dog();

        Brain &getBrain(void) const;
        void setBrain(Brain const &brain);
        void makeSound() const;
};

#endif