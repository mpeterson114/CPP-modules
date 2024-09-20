/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:35:46 by mpeterso          #+#    #+#             */
/*   Updated: 2024/09/20 12:50:38 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "\033[34m------------------------------------------------------------------------\033[0m" << std::endl;
    std::cout << "\033[34m  Test: Able to sign form, grades in valid range to sign and execute... \033[0m" << std::endl;
    std::cout << "\033[34m------------------------------------------------------------------------\033[0m" << std::endl;
    Bureaucrat A("A", 10);
    std::cout << "-Name: " << A.getName() << std::endl;
    std::cout << "-Grade: " << A.getGrade() << std::endl;
    std::cout << "\033[34m   Incrementing...\033[0m" << std::endl;
    A.increment(8);
    std::cout << "-New grade: " << A.getGrade() << std::endl;
    std::cout << std::endl;
    Form abc("abc", 2, 2);
    std::cout << abc << std::endl;
    try
    {
        A.signForm(abc);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << abc << std::endl;
    std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
    std::cout << "\033[34m  Test: Attempting to sign same form twice... \033[0m" << std::endl;
    std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
    try
    {
        A.signForm(abc);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "\033[34m------------------------------------------------------------\033[0m" << std::endl;
    std::cout << "\033[34m  Test: Unable to sign form, Bureaucrat's grades too low... \033[0m" << std::endl;
    std::cout << "\033[34m------------------------------------------------------------\033[0m" << std::endl;
    Bureaucrat B("B", 140);
    std::cout << "-Name: " << B.getName() << std::endl;
    std::cout << "-Grade: " << B.getGrade() << std::endl;
    std::cout << std::endl;
    Form xyz("xyz", 135, 135);
    std::cout << xyz << std::endl;
    try
    {
        B.signForm(xyz);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << xyz << std::endl;
    std::cout << std::endl;
    std::cout << "\033[34m--------------------------------------------------------------------------\033[0m" << std::endl;
    std::cout << "\033[34m  Test: Unable to create forms/Bureaucrats, grades out of valid range...  \033[0m" << std::endl;
    std::cout << "\033[34m--------------------------------------------------------------------------\033[0m" << std::endl;
    try
    {
        std::cout << "Attempting to create Form 'lmn'..." << std::endl;
        Form lmn("lmn", 141, 155);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << "Re-attempting to create Form 'lmn'..." << std::endl;
        Form lmn("lmn", 141, 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << "Attempting to create Bureaucrat 'C'..." << std::endl;
        Bureaucrat C("C", 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << "Re-attempting to create Bureaucrat 'C'..." << std::endl;
        Bureaucrat C("C", 160);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
}
