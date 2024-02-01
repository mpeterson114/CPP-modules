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

    std::cout << "Please enter " << prompt << ": " << std::endl << "> ";
    if (!std::getline(std::cin, line) || std::cin.eof())
    {
        _error = true;
        std::cout << std::endl;
        return (std::string());
    }
    // line = trimBlank(line);
    return (line);
}
 // incrementIndex necessary? or include directly in main...

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
                std::cout << "Error: No contact found at i [" << i << "]. Please try again." << std::endl;
                return (false);
            }
        }
    }
    std::cout << "Error: \'" << input << "' is not a valid i. Must be a number between '0' and '7'" << std::endl;
    return (false);
}

/* PUBLIC FUNCTIONS */

std::string Phonebook::trimBlank(std::string str)
{
    int i = 0;
    int end = str.length() - 1;

    while (std::isspace(str[i]))
        i++;
    while (std::isspace(str[end]))
        end--;
    return (str.substr(i, end - i + 1));
}

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
	std::cout << "Contact successfully saved." << std::endl;
	return (true);	
}

bool Phonebook::searchContact(void)
{
	std::string input;

	if (_index == -1) {
		std::cout << "No contacts saved. Please ADD a contact." << std::endl;
		return (true);
	}
	this->_displayTable();
	input = _getInput("the i of the contact to display");
	if (input.empty())
		return (false);
	this->_showContactAtIndex((std::string const)input);
	return (true);
}
