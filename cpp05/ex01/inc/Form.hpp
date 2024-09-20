/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:35:37 by mpeterso          #+#    #+#             */
/*   Updated: 2024/09/20 12:36:42 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool _isSigned;
        int const _signGrade;
        int const _exGrade;
        Form();

    public:
        Form(std::string const &name, int signGrade, int exGrade);
        Form(Form const &copy);
        Form &operator=(Form const &copy);
        ~Form();

        std::string const &getName() const;
        bool getIsSigned() const;
        int const &getSignGrade() const;
        int const &getExGrade() const;
        void beSigned(Bureaucrat &bureaucrat);

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
        class IsAlreadySigned : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &stream, const Form &other);

#endif
