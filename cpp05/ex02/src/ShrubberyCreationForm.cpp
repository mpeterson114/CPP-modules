#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137)
{
    setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy.getName(), copy.getSignGrade(), copy.getExGrade())
{
    setTarget(copy.getTarget());
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
    if (this != &copy)
        this->setTarget(copy.getTarget());
    return *this;
}
        
        
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getExGrade())
        throw AForm::GradeTooLowException();
    else
        // Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.
}

std::ostream &operator<<(std::ostream &stream, const ShrubberyCreationForm &other)
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