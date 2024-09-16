#include "Bureaucrat.hpp"
        
/* CONSTRUCTORS/DESTRUCTOR */
Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade = grade;
    std::cout << "\033[32mBureaucrat " << this->_name << " has been created\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name), _grade(copy._grade)
{
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "\033[38;5;161mBureaucrat " << this->_name << " has been destroyed\033[0m" << std::endl;
}

/* OPERATOR OVERLOADS */
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &copy)
        this->_grade = copy._grade;
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& other)
{
    stream << other.getName() << ", bureaucrat grade " << other.getGrade();
    return (stream);
}

/* MEMBER FUNCTIONS */
std::string const &Bureaucrat::getName() const
{
    return this->_name;
}

int const &Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::increment(int amount)
{
    if (this->_grade - amount < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade -= amount;
}

void Bureaucrat::decrement(int amount)
{
    if (this->_grade + amount > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade += amount;
}

/* EXCEPTIONS */
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "\033[38;5;209mGrade too high! Max value allowed = 1\033[0m";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "\033[38;5;209mGrade too low! Min value allowed = 150\033[0m";
}