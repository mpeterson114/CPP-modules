/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:07:25 by mpeterso          #+#    #+#             */
/*   Updated: 2024/03/07 13:11:42 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug(void)
{
    std::cout << "DEBUG: " << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;   
    std::cout << std::endl;
}

void Harl::info(void)
{
    std::cout << "INFO: " << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;   
    std::cout << std::endl;
}

void Harl::warning(void)
{
    std::cout << "WARNING: " << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;   
    std::cout << std::endl;
}

void Harl::error(void)
{
    std::cout << "ERROR: " << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;   
    std::cout << std::endl;
}

void Harl::complain(std::string level)
{
    void    (Harl::*complaint_options[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*complaint_options[i])();
            return ;
        }
    }
}

