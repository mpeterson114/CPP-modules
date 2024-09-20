/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:36:46 by mpeterso          #+#    #+#             */
/*   Updated: 2024/09/20 12:25:18 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << " *New Intern was hired* " <<  std::endl;
}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern::~Intern()
{
    std::cout << "Intern was destroyed" << std::endl;
}
        
Intern &Intern::operator=(const Intern &copy)
{
    if (this != &copy)
        *this = copy;
    return *this;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    int i;
    std::string formType[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    for (i = 0; i < 3; i++)
    {
        if (name == formType[i])
            break ;
    }

    switch(i)
    {
        case 0:
            std::cout << "Intern created " ;
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "Intern created " ;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern created " ;
            return new PresidentialPardonForm(target);
        default:
            throw Intern::WrongNameException();
    }
}

const char *Intern::WrongNameException::what() const throw()
{
    return "\033[38;5;209mNo form exists with the entered name, try again!\033[0m";
}
