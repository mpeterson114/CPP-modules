/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:36:49 by mpeterso          #+#    #+#             */
/*   Updated: 2024/09/20 12:13:15 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern RandomIntern;
    Bureaucrat A("A", 3);
    std::cout << "\033[34m------------------------------------\033[0m" << std::endl;
    std::cout << "\033[34m          Invalid Name Test         \033[0m" << std::endl;
    std::cout << "\033[34m------------------------------------\033[0m" << std::endl;
    AForm *err;
    try
    {
        err = RandomIntern.makeForm("robotomy request", "Bender");
        delete err;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "\033[34m------------------------------------\033[0m" << std::endl;
    std::cout << "\033[34m             SCF Form-OK            \033[0m" << std::endl;
    std::cout << "\033[34m------------------------------------\033[0m" << std::endl;
    AForm *scf;
    std::cout << std::endl;
    std::cout << A << std::endl;
    try
    {
        scf = RandomIntern.makeForm("ShrubberyCreationForm", "school");
        std::cout << *scf << std::endl;
        scf->beSigned(A);
        scf->execute(A);
        std::cout << std::endl;
        delete scf;
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "\033[34m------------------------------------\033[0m" << std::endl;
    std::cout << "\033[34m             RRF Form-OK            \033[0m" << std::endl;
    std::cout << "\033[34m------------------------------------\033[0m" << std::endl;
    AForm *rrf;
    std::cout << A << std::endl;
    std::cout << std::endl;
    try
    {
        rrf = RandomIntern.makeForm("RobotomyRequestForm", "John Doe");
        std::cout << *rrf << std::endl;
        rrf->beSigned(A);
        rrf->execute(A);
        std::cout << std::endl;
        delete rrf;
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "\033[34m------------------------------------\033[0m" << std::endl;
    std::cout << "\033[34m             PPF Form-OK            \033[0m" << std::endl;
    std::cout << "\033[34m------------------------------------\033[0m" << std::endl;
    AForm *ppf;
    std::cout << A << std::endl;
    std::cout << std::endl;
    try
    {
        ppf = RandomIntern.makeForm("PresidentialPardonForm", "Random Criminal");
        std::cout << *ppf << std::endl;
        ppf->beSigned(A);
        ppf->execute(A);
        std::cout << std::endl;
        delete ppf;
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }
}
