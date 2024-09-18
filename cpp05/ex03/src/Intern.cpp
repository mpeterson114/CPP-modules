#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern::~Intern()
{
    std::cout << "Intern destroyed" << std::endl;
}
        
Intern &Intern::operator=(const Intern &copy)
{
    if (this != &copy)
        *this = copy;
    return *this;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    int i;
    std::string formType[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    for (i = 0; i < 3; i++)
    {
        if (name == formType[i])
            break ;
    }

    switch(i)
    {
        case 0:
            std::cout << "A ShrubberyCreationForm has been created" << std::endl;
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "A RobotomyRequestForm has been created" << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "A PresidentialPardonForm has been created" << std::endl;
            return new PresidentialPardonForm(target);
        default:
            throw Intern::WrongNameException();
    }
}

const char *Intern::WrongNameException::what() const throw()
{
    return "\033[38;5;209mNo form exists with the entered name, try again!\033[0m";
}
