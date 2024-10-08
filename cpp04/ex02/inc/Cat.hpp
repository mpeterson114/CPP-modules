/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:02:26 by mpeterso          #+#    #+#             */
/*   Updated: 2024/08/25 17:12:14 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
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
