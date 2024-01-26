#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
private:
    Contact _contacts[8];
    int _index;
    bool _error;
    
    std::string _getInput(std::string const prompt);
    void    _indexCheck(void);
    bool    _displayContactByIndex(std::string const input) const;
    void    _displayTable(void) const;
    void    _writeContactToTable(int const index) const;
    void    _formatTableInput(std::string str) const;

public:
    Phonebook();
    ~Phonebook();

    std::string trimBlank(std::string str);
    bool addContact(void);
    void displayContact(int index) const;
    bool searchContact(void);
};

#endif