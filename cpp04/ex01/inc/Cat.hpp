/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:02:26 by mpeterso          #+#    #+#             */
/*   Updated: 2024/08/15 12:31:24 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
    private:
        Brain *_brain;
        
    public:
        Cat();
        Cat(Cat const &copy);
        Cat &operator=(Cat const &copy);
        ~Cat();

        Brain &getBrain(void) const;
        void setBrain(Brain const &brain);
        void makeSound() const;
};

#endif