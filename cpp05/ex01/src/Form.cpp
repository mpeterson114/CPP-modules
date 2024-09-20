/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:35:43 by mpeterso          #+#    #+#             */
/*   Updated: 2024/09/20 12:36:54 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/* CONSTRUCTORS, ASSIGNMENT OPERATOR, DESTRUCTOR */
Form::Form(std::string const &name, int signGrade, int exGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _exGrade(exGrade)
{
    if (signGrade > 150 || exGrade > 150)
        throw Form::GradeTooLowException();
    else if (signGrade < 1 || exGrade < 1)
        throw Form::GradeTooHighException();
    std::cout << "\033[32mForm " << this->_name << " has been created.\033[0m" << std::endl;
}

Form::Form(Form const &copy) : _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _exGrade(copy._exGrade)
{
    std::cout << "Copy constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "\033[38;5;161mForm " << this->_name << " has been destroyed.\033[0m" << std::endl;
}

/* OPERATOR OVERLOADS */
Form &Form::operator=(Form const &copy) 
{
    std::cout << "Form assignment operator called" << std::endl;
    if (this != &copy)
        _isSigned = copy._isSigned;
    return *this;
}

std::ostream &operator<<(std::ostream &stream, const Form &other)
{
    stream << "-Form name: " << other.getName() << std::endl;
    stream << "-Grade needed to sign: " << other.getSignGrade() << std::endl;
    stream << "-Grade needed to execute: " << other.getExGrade() << std::endl;
    stream << "-Signed?: ";
    if (other.getIsSigned())
        stream << "YES" << std::endl;
    else
        stream << "NO" << std::endl;
    return (stream);
}

/* MEMBER FUNCTIONS */
std::string const &Form::getName() const
{
    return this->_name;
}

bool Form::getIsSigned() const
{
    return this->_isSigned;
}

int const &Form::getSignGrade() const
{
    return this->_signGrade;
}

int const &Form::getExGrade() const
{
    return this->_exGrade;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)
        throw Form::GradeTooLowException();
    else
        this->_isSigned = true;
}

/* EXCEPTIONS */
const char *Form::GradeTooHighException::what() const throw()
{
    return "\033[38;5;209mgrade is too high!\033[0m";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "\033[38;5;209mgrade is too low!\033[0m";
}

const char *Form::IsAlreadySigned::what() const throw()
{
    return "\033[38;5;209mThis form is already signed!\033[0m";
}
