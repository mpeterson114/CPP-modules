/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:25:25 by mpeterso          #+#    #+#             */
/*   Updated: 2024/03/07 15:25:26 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};

#endif