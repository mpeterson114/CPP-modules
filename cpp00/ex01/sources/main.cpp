/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:46:14 by mpeterso          #+#    #+#             */
/*   Updated: 2024/03/21 14:30:37 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

std::string getCommand(void) {
    std::string command;

    if (!std::getline(std::cin, command) || std::cin.eof()) {
        std::cout << "EXIT" << std::endl;
        return ("EXIT");
    }
    for (std::string::iterator it = command.begin(); it !=command.end(); it++){
        *it = std::toupper(*it);
    }
    return (command);
}

int main(void)
{
    Phonebook book;
    std::string command;

    system("clear");
    std::cout << std::endl << "\033[38;5;206mOpening Phonebook...\033[0m" << std::endl;
    while (true){
        std::cout   << std::endl
                    <<"\033[38;5;206m+-----------------MAIN MENU-----------------+\033[0m" << std::endl
                    << std::endl
                    << "\033[38;5;210mPlease enter a command ('ADD', 'SEARCH', or 'EXIT')\033[0m" << std::endl << ">";
        command = getCommand();
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
            std::cout << "\033[38;5;161mInvalid input, please choose from one of the following commands: ADD, SEARCH, or EXIT\033[0m" << std::endl;
    }
    std::cout << "\033[38;5;206mExiting Phonebook...goodbye!\033[0m" << std::endl;
    return (0);
}