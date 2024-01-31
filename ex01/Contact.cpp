#include "Contact.hpp"

/* Constructor/Destructor */
Contact::Contact()
{
}

Contact::~Contact()
{
}

/* Getters */
std::string const Contact::getFirstName(void) const
{
    return (this->_firstname);
}

std::string const Contact::getLastName(void) const
{
    return (this->_lastname);
}

std::string const Contact::getNickname(void) const
{
    return (this->_nickname);
}

std::string const Contact::getPhoneNumber(void) const
{
    return (this->_phonenumber);
}

std::string const Contact::getSecret(void) const
{
    return (this->_secret);
}

/* Setters */
bool Contact::setFirstName(std::string str)
{
    if (str.empty())
    {
        return (false);
    }
    else if (!_containsOnlySpaces(str))
    {
       std::cout << "Invalid input: Entry cannot contain only whitespace" << std::endl;
       return (false);
    }
    else if (!_isValidWord(str))
    {
        std::cout << "Invalid input: Names can only contain letters, spaces and/or hyphens" << std::endl;
        return (false);
    }
    this->_firstname = str;
    return (true);
}

bool Contact::setLastName(std::string str)
{
    if (str.empty())
    {
        return (false);
    }
    else if (!_containsOnlySpaces(str))
    {
       std::cout << "Invalid input: entry cannot contain only whitespace" << std::endl;
       return (false);
    }
    else if (!_isValidWord(str))
    {
        std::cout << "Invalid input: Names can only contain letters, spaces and/or hyphens" << std::endl;
        return (false);
    }
    this->_lastname = str;
    return (true);
}

bool Contact::setNickname(std::string str)
{
    if (str.empty())
    {
        return (false);
    }
    else if (!_containsOnlySpaces(str))
    {
       std::cout << "Invalid input: entry cannot contain only whitespace" << std::endl;
       return (false);
    }
    else if (!_isValidWord(str))
    {
        std::cout << "Invalid input: Names can only contain letters, spaces and hyphens" << std::endl;
        return (false);
    }
    this->_nickname = str;
    return (true);
}

bool Contact::setPhoneNumber(std::string str)
{
    if (str.empty())
    {
        return (false);
    }
    else if (!_containsOnlySpaces(str))
    {
       std::cout << "Invalid input: entry cannot contain only whitespace" << std::endl;
       return (false);
    }
    else if (!_isValidNumber(str))
    {
        std::cout << "Invalid input: Phone numbers can only contain digits, spaces and hyphens" << std::endl;
        return (false);
    }
    this->_phonenumber = str;
    return (true);
}

bool Contact::setSecret(std::string str)
{
    if (str.empty())
        return (false);
    else if (!_containsOnlySpaces(str))
    {
       std::cout << "Invalid input: entry cannot contain only whitespace" << std::endl;
       return (false);
    }
    this->_secret = str;
    return (true);
}

/* Private Member Functions */
bool Contact::_containsOnlySpaces(std::string const s)
{
    bool onlySpaces = true;
    for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
        char c = *it;
        if (!std::isspace(c)) {
            onlySpaces = false;
            break ;
        }
        else 
            onlySpaces = true; 
    }
    if (onlySpaces == true)
        return (false);
    return (true);
}

bool Contact::_isValidWord(std::string const s)
{
    for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
        char c = *it;
        if (!std::isalpha(c) && c != ' ' && c != '-') {
             return (false);
        }  
    }   
    return (true);
}

bool Contact::_isValidNumber(std::string const s)
{
    for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
        char c = *it;
        if (!std::isdigit(c) && c != ' ' && c != '-') {
             return (false);
        }  
    }
    return (true);
}

/* Public Member Functions */
bool Contact::isEmpty(void) const {
    if (this->_firstname.empty() ||
    this->_lastname.empty() ||
    this->_nickname.empty() ||
    this->_phonenumber.empty() ||
    this->_secret.empty())
        return (true);
    bool containsOnlySpaces = true;

    return (false);
}

bool Contact::displayContactInfo(void) const {
    if (this->isEmpty())
        return (false);
    std::cout   << "Enter first name: " << this->getFirstName() << std::endl
                << "Enter last name: " << this->getLastName() << std::endl
                << "Enter nickname: " << this->getNickname() << std::endl
                << "Enter phone number: " << this->getPhoneNumber() << std::endl
                << "Enter darkest secret: " << this->getSecret() << std::endl;
    return (true);
}