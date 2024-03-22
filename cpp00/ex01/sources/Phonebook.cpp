/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:46:41 by mpeterso          #+#    #+#             */
/*   Updated: 2024/03/22 17:25:57 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() : _index(-1), _error(false)
{ 
}

Phonebook::~Phonebook()
{
}

/* PRIVATE FUNCTIONS */

std::string Phonebook::_getInput(std::string const prompt)
{
    std::string line;

    std::cout << "\033[38;5;209mPlease enter " << prompt << ": " << std::endl << "> \033[0m";
    if (!std::getline(std::cin, line) || std::cin.eof())
    {
        _error = true;
        std::cout << std::endl;
        return (std::string());
    }
    return (line);
}

void Phonebook::_displayTable() const
{
    std::cout   << "+------------PHONEBOOK CONTACTS-------------+" << std::endl
                << "|  Index   |First Name| Last Name| Nickname |" << std::endl
                << "+----------+----------+----------+----------+" << std::endl;
    int i = 0;
    while (i < 8)
    {
        if (!this->_contacts[i].isEmpty()) {
            std::cout << "|" << std::setw(10) << i << "|";
            _formatTableInput(this->_contacts[i].getFirstName());
            _formatTableInput(this->_contacts[i].getLastName());
            _formatTableInput(this->_contacts[i].getNickname());
            std::cout   << std::endl
            << "+----------+----------+----------+----------+" << std::endl;
        }
        i++;
    }
    std::cout << std::endl;
    return ;
}

void Phonebook::_formatTableInput(std::string str) const
{
    if (str.length() > 10){
        str.resize(9);
        str += ".";
    }
    std::cout << std::setw(10) << str << "|";
    return ;
}

bool Phonebook::_showContactAtIndex(std::string const input) const
{
    int i;
    if (input.length() == 1 && std::isdigit(input[0])) {
        i = input[0] - '0';
        if (i >= 0 && i <= 7) {
            if (this->_contacts[i].displayContactInfo())
                return (true);
            else {
                std::cout << "\033[38;5;161mError: No contact found at index [" << i << "]. Please try again.\033[0m" << std::endl;
                return (false);
            }
        }
    }
    std::cout << "\033[38;5;161mError: \'" << input << "' is not a valid index. Must be a number between '0' and '7'\033[0m" << std::endl;
    return (false);
}

/* PUBLIC FUNCTIONS */

bool Phonebook::addContact(void) 
{
	std::string input;

	_index++;
	if (_index > 7) {
		_index = 0;
	}
	while (!_error) {
		input = _getInput("first name");
		if (_error || this->_contacts[_index].setFirstName(input))
			break ;
	}
	while (!_error) {
		input = _getInput("last name");
		if (_error || this->_contacts[_index].setLastName(input))
			break ;
	}
	while (!_error) {
		input = _getInput("nickname");
		if (_error || this->_contacts[_index].setNickname(input))
			break ;
	}
	while (!_error) {
		input = _getInput("phone number");
		if (_error || this->_contacts[_index].setPhoneNumber(input))
			break ;
	}
	while (!_error) {
		input = _getInput("darkest secret");
		if (_error || this->_contacts[_index].setSecret(input))
			break ;
	}
	if (_error){
		_error = false;
		return (false);
	}
	std::cout << "\033[38;5;192mContact successfully saved.\033[0m" << std::endl;
	return (true);	
}

bool Phonebook::searchContact(void)
{
	std::string input;

	if (_index == -1) {
		std::cout << "\033[38;5;161mNo contacts saved. Please ADD a contact.\033[0m" << std::endl;
		return (true);
	}
	this->_displayTable();
	input = _getInput("the index of the contact to display");
	this->_showContactAtIndex((std::string const)input);
	return (true);
}
