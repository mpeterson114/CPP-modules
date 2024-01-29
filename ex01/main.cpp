#include "Phonebook.hpp"

std::string getCommand(Phonebook *book) {
    std::string command;

    if (!std::getline(std::cin, command) || std::cin.eof()) {
        std::cout << "EXIT" << std::endl;
        return ("EXIT");
    }
    command = book->trimBlank(command);
    for (std::string::iterator it = command.begin(); it !=command.end(); it++){
        char c = *it;
        std::toupper(c);
    }
    return (command);
}

int main(void)
{
    Phonebook book;
    std::string command;

    std::cout << std::endl << "Opening Phonebook..." << std::endl;
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
                    else {
                        std::cout << "Invalid input, please choose from one of the following commands: ADD, SEARCH, or EXIT" << std::endl;
                    }
                    std::cout << "Exiting Phonebook...goodbye!" << std::endl;
                    return (0);
    }

}