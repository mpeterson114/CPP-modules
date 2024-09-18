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
    else if (this->getIsSigned() == false)
        throw AForm::FormNotSigned();
    else
    {
        std::ofstream outfile;
        
        outfile.open((this->getTarget() + "_shrubbery").c_str());
        if (outfile.fail()) 
        {
            std::cerr << "\033[38;5;161mError: Unable to create the file.\033[0m" << std::endl;
            return ;
        }
        outfile <<  "      /\\      \n"
                <<  "     /\\*\\     \n"
                <<  "    /\\O\\*\\    \n"
                <<  "   /*/\\/\\/\\   \n"
                <<  "  /\\O\\/\\*\\/\\  \n"
                <<  " /\\*\\/\\*\\/\\/\\ \n"
                <<  "/\\O\\/\\/*/\\/O/\\\n"
                <<  "      ||      \n"
                <<  "      ||      \n"
                <<  "      ||      \n";
        outfile.close();
        std::cout << "\033[32m" << executor.getName() << " has created a shrubbery at " << this->getTarget() << "_shrubbery.\033[0m" << std::endl;
    }
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