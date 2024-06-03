/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:48:14 by mpeterso          #+#    #+#             */
/*   Updated: 2024/06/03 13:19:41 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() 
{
    std::cout << "Brain constructor called" << std::endl;   
}

Brain::Brain(Brain const &copy)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = copy;
}

Brain &Brain::operator=(Brain const &copy)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &copy)
    {
        size_t length = (sizeof(this->_ideas)/sizeof(this->_ideas[0]));
        for (int i = 0; i < length; i++)
            this->_ideas[i] = copy._ideas[i];
    }
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}
