#include <iostream>

int main()
{
    std::string greeting = "HI THIS IS BRAIN";
    std::string *stringPTR = &greeting;
    std::string &stringREF = greeting;

    std::cout << "Memory address of 'greeting': " << &greeting << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "Value of 'greeting': " << greeting << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
    return (0);
}