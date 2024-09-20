/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:35:14 by mpeterso          #+#    #+#             */
/*   Updated: 2024/09/20 12:53:45 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

/* Declaring default constructor as private explicitly prevents 
    default construction without specifying the necessary parameters.

    Particularly useful when 'const' member variables are involved, 
    since their values need to be assigned upon creation and cannot 
    be modified afterward. */

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
         Bureaucrat();

    public:
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &copy);
        Bureaucrat &operator=(Bureaucrat const &copy);
        ~Bureaucrat();

        std::string const &getName() const;
        int const &getGrade() const;
        void increment(int amount);
        void decrement(int amount);

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &other);

#endif
