#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5)
{
    setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy.getName(), copy.getSignGrade(), copy.getExGrade())
{
    setTarget(copy.getTarget());
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
    if (this != &copy)
        this->setTarget(copy.getTarget());
    return *this;
}
       
PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getExGrade())
        throw AForm::GradeTooLowException();
    else if (this->getIsSigned() == false)
        throw AForm::FormNotSigned();
    else
        std::cout << "\033[32m" << this->getTarget() << " has been pardoned by Zaphod Beeblebrox.\033[0m" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const PresidentialPardonForm &other)
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