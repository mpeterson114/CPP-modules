/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:36:18 by mpeterso          #+#    #+#             */
/*   Updated: 2024/09/20 12:34:48 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

/* 'srand()' sets seed for start of random numbers list based on current time.
Necessary or 'rand()' would generate the same sequence of random numbers each time.

Since the seed is based on the current time, we know the random numbers sequence
will be different each time the function is called */

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45)
{
    setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy.getName(), copy.getSignGrade(), copy.getExGrade())
{
    setTarget(copy.getTarget());
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
    if (this != &copy)
        this->setTarget(copy.getTarget());
    return *this;
}
       
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getExGrade())
        throw AForm::GradeTooLowException();
    else if (this->getIsSigned() == false)
        throw AForm::FormNotSigned();
    else
    {
        std::cout << "\033[32m ** Loud drilling noises... **\033[0m" << std::endl;
        std::srand(std::time(NULL));
        if (std::rand() % 2 == 0)
            std::cout << "\033[32m" << this->getTarget() << " has been successfully robotomized.\033[0m" << std::endl;
        else
            std::cout << "\033[32mFailure: " << this->getTarget() << " unable to be robotomized.\033[0m" << std::endl;
    }
}

std::ostream &operator<<(std::ostream &stream, const RobotomyRequestForm &other)
{
    stream << "-Form name: " << other.getName() << std::endl;
    stream << "-Grade needed to sign: " << other.getSignGrade() << std::endl;
    stream << "-Grade needed to execute: " << other.getExGrade() << std::endl;
    stream << "-Target: " << other.getTarget() << std::endl;
    stream << "-Signed?: ";
    if (other.getIsSigned())
        stream << "YES" << std::endl;
    else
        stream << "NO" << std::endl;
    return (stream);
}
