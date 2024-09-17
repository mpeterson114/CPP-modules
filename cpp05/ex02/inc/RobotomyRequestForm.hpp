#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        RobotomyRequestForm();

    public:
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &stream, const RobotomyRequestForm &other);

#endif