#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact {
private:
        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        std::string _phonenumber;
        std::string _secret;

        bool _isValidWord(std::string const s);
        bool _isValidNumber(std::string const input);
        
public:
        Contact();
        ~Contact();

        bool    isEmpty(void) const;
        bool    displayContactInfo(void) const;
        bool _containsOnlySpaces(std::string const s);
        // Getters
        std::string const getFirstName(void) const;
        std::string const getLastName(void) const;
        std::string const getNickname(void) const;
        std::string const getPhoneNumber(void) const;
        std::string const getSecret(void) const;

        // Setters
        bool setFirstName(std::string str);
        bool setLastName(std::string str);
        bool setNickname(std::string str);
        bool setPhoneNumber(std::string str);
        bool setSecret(std::string str);
};

#endif