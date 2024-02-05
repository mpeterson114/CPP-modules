/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:46:31 by mpeterso          #+#    #+#             */
/*   Updated: 2024/02/01 09:46:32 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    // void _indexCheck(void);
    bool _showContactAtIndex(std::string const input) const;
    void _displayTable() const;
    void _formatTableInput(std::string str) const;

public:
    Phonebook();
    ~Phonebook();

    std::string trimBlank(std::string str);
    bool addContact(void);
    // void displayContact(int index) const;
    bool searchContact(void);
};

#endif