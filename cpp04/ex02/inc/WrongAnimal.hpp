/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:19:58 by mpeterso          #+#    #+#             */
/*   Updated: 2024/08/25 17:12:18 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
    protected:
        std::string _type;
    
    public:
        WrongAnimal();
        WrongAnimal(std::string const &type);
        WrongAnimal(WrongAnimal const &copy);
        WrongAnimal &operator=(WrongAnimal const &copy);
        virtual ~WrongAnimal();

        std::string const &getType(void) const;
        void makeSound() const;
};

#endif
