/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:46:50 by mpeterso          #+#    #+#             */
/*   Updated: 2024/03/24 10:34:48 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

/* GETTERS */
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

/* SETTERS */
bool Contact::setFirstName(std::string str)
{
    if (str.empty())
    {
        return (false);
    }
    else if (!_containsOnlySpaces(str))
    {
       std::cout << "\033[38;5;161mInvalid input: Entry cannot contain only whitespace\033[0m" << std::endl;
       return (false);
    }
    else if (!_isValidWord(str))
    {
        std::cout << "\033[38;5;161mInvalid input: Names can only contain letters, spaces and/or hyphens\033[0m" << std::endl;
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
       std::cout << "\033[38;5;161mInvalid input: entry cannot contain only whitespace\033[0m" << std::endl;
       return (false);
    }
    else if (!_isValidWord(str))
    {
        std::cout << "\033[38;5;161mInvalid input: Names can only contain letters, spaces and/or hyphens\033[0m" << std::endl;
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
       std::cout << "\033[38;5;161mInvalid input: entry cannot contain only whitespace\033[0m" << std::endl;
       return (false);
    }
    else if (!_isValidWord(str))
    {
        std::cout << "\033[38;5;161mInvalid input: Names can only contain letters, spaces and hyphens\033[0m" << std::endl;
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
       std::cout << "\033[38;5;161mInvalid input: entry cannot contain only whitespace\033[0m" << std::endl;
       return (false);
    }
    else if (!_isValidNumber(str))
    {
        std::cout << "\033[38;5;161mInvalid input: Phone numbers can only contain digits, spaces and hyphens\033[0m" << std::endl;
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
       std::cout << "\033[38;5;161mInvalid input: entry cannot contain only whitespace\033[0m" << std::endl;
       return (false);
    }
    this->_secret = str;
    return (true);
}

/* PRIVATE FUNCTIONS */
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

/* PUBLIC FUNCTIONS */
bool Contact::isEmpty(void) const {
    if (this->_firstname.empty() ||
    this->_lastname.empty() ||
    this->_nickname.empty() ||
    this->_phonenumber.empty() ||
    this->_secret.empty())
        return (true);
    return (false);
}

bool Contact::displayContactInfo(void) const {
    if (this->isEmpty())
        return (false);
    std::cout   << "First name: " << this->getFirstName() << std::endl
                << "Last name: " << this->getLastName() << std::endl
                << "Nickname: " << this->getNickname() << std::endl
                << "Phone number: " << this->getPhoneNumber() << std::endl
                << "Darkest secret: " << this->getSecret() << std::endl;
    return (true);
}