/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:39:06 by mpeterso          #+#    #+#             */
/*   Updated: 2024/08/25 17:11:55 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    private:
        std::string _ideas[100];
        
    public:
        Brain();
        Brain(Brain const &copy);
        Brain &operator=(Brain const &copy);
        ~Brain();
  
        std::string const &getIdea(int const &index) const;
        void setIdea(std::string const &idea, int const &index);
};

#endif
