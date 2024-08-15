/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:48:14 by mpeterso          #+#    #+#             */
/*   Updated: 2024/08/15 12:53:12 by mpeterso         ###   ########.fr       */
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
        for (size_t i = 0; i < length; i++)
            this->_ideas[i] = copy._ideas[i];
    }
    return (*this);
}

std::string const &Brain::getIdea(int const &index) const
{
    if (index >= 0 && index <= 100)
        return (this->_ideas[index]);
    return (this->_ideas[0]);
}
        
        
void Brain::setIdea(std::string const &idea, int const &index)
{
    this->_ideas[index] = idea;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}
