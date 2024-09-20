/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:35:55 by mpeterso          #+#    #+#             */
/*   Updated: 2024/09/20 12:33:37 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

/* Base class member variables left as private (not protected), 
    derived classes can still access through public getter functions. 
    Stricter encapsulation 
    
    -'_name' can be const since it doesn't change after creation, 
        doesn't need setter

    -'_target' shouldn't be const; variable that only applies with derived
        classes and will be set after creation via derived class constructors 
        (needs setter function) */

class AForm
{
    private:
        std::string const _name;
        bool _isSigned;
        int const _signGrade;
        int const _exGrade;
        std::string _target;
        AForm();

    public:
        AForm(std::string const &name, int signGrade, int exGrade);
        AForm(AForm const &copy);
        AForm &operator=(AForm const &copy);
        virtual ~AForm();

        std::string const &getName() const;
        bool getIsSigned() const;
        int const &getSignGrade() const;
        int const &getExGrade() const;
        std::string const &getTarget() const;
        
        void setTarget(const std::string &target);

        void beSigned(Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;

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
        class FormNotSigned : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &stream, const AForm &other);

#endif
