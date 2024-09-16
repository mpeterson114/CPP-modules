#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    protected:
        std::string const _name;
        bool _isSigned;
        int const _signGrade;
        int const _exGrade;
        AForm();

    public:
        AForm(std::string const &name, int signGrade, int exGrade);
        AForm(AForm const &copy);
        AForm &operator=(AForm const &copy);
        ~AForm();

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

std::ostream &operator<<(std::ostream &stream, const AForm &other);

#endif