#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        PresidentialPardonForm();

    public:
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &copy);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &stream, const PresidentialPardonForm &other);

#endif