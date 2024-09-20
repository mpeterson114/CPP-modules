/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:36:41 by mpeterso          #+#    #+#             */
/*   Updated: 2024/09/20 12:24:18 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* CONSTRUCTORS, ASSIGNMENT OPERATOR, DESTRUCTOR */
AForm::AForm(std::string const &name, int signGrade, int exGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _exGrade(exGrade)
{
    if (signGrade > 150 || exGrade > 150)
        throw AForm::GradeTooLowException();
    else if (signGrade < 1 || exGrade < 1)
        throw AForm::GradeTooHighException();
    std::cout << "new form: " << this->_name << std::endl;
}

AForm::AForm(AForm const &copy) : _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _exGrade(copy._exGrade)
{
    std::cout << "Copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "Form " << this->_name << " has been destroyed." << std::endl;
}

/* OPERATOR OVERLOADS */
AForm &AForm::operator=(AForm const &copy) 
{
    std::cout << "Form assignment operator called" << std::endl;
    if (this != &copy)
        _isSigned = copy._isSigned;
    return *this;
}

std::ostream &operator<<(std::ostream &stream, const AForm &other)
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
std::string const &AForm::getName() const
{
    return this->_name;
}

bool AForm::getIsSigned() const
{
    return this->_isSigned;
}

int const &AForm::getSignGrade() const
{
    return this->_signGrade;
}

int const &AForm::getExGrade() const
{
    return this->_exGrade;
}

std::string const &AForm::getTarget() const
{
    return this->_target;
}

void AForm::setTarget(const std::string &target)
{
    this->_target = target;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)
        throw AForm::GradeTooLowException();
    else
        this->_isSigned = true;
}

/* EXCEPTIONS */
const char *AForm::GradeTooHighException::what() const throw()
{
    return "\033[38;5;209mgrade is too high!\033[0m";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "\033[38;5;209mgrade is too low!\033[0m";
}

const char *AForm::IsAlreadySigned::what() const throw()
{
    return "\033[38;5;209mThis form is already signed!\033[0m";
}

const char *AForm::FormNotSigned::what() const throw()
{
    return "\033[38;5;209mThis form has not been signed!\033[0m";
}
