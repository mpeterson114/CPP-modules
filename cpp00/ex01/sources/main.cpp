/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:46:14 by mpeterso          #+#    #+#             */
/*   Updated: 2024/02/01 09:46:15 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

// void leaks(void)
// {
//     system("leaks myphonebook");
// }

std::string getCommand(Phonebook *book) {
    std::string command;

    if (!std::getline(std::cin, command) || std::cin.eof()) {
        std::cout << "EXIT" << std::endl;
        return ("EXIT");
    }
    command = book->trimBlank(command);
    for (std::string::iterator it = command.begin(); it !=command.end(); it++){
        *it = std::toupper(*it);
    }
    return (command);
}

int main(void)
{
    Phonebook book;
    std::string command;

    std::cout << std::endl << "Opening Phonebook..." << std::endl;
    // atexit(leaks);
    while (true){
        std::cout   << std::endl
                    <<"+-----------------MAIN MENU-----------------+" << std::endl
                    << std::endl
                    << "Please enter a command ('ADD', 'SEARCH', or 'EXIT')" << std::endl << ">";
        command = getCommand(&book);
        if (command == "EXIT")
             break ;
        else if (command == "ADD") {
            if (!book.addContact())
                break ;
        }
        else if (command == "SEARCH") {
            if (!book.searchContact())
                 break ;
        }
        else
            std::cout << "Invalid input, please choose from one of the following commands: ADD, SEARCH, or EXIT" << std::endl;
    }
    std::cout << "Exiting Phonebook...goodbye!" << std::endl;
    return (0);
}