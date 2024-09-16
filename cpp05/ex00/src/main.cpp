#include "Bureaucrat.hpp"

int main()
{
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "   Incrementing/Decrementing Tests...   " << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    Bureaucrat A("A", 10);
    std::cout << "-Name: " << A.getName() << std::endl;
    std::cout << "-Grade: " << A.getGrade() << std::endl;
    std::cout << "\033[34m   Incrementing...\033[0m" << std::endl;
    A.increment(8);
    std::cout << "New grade: " << A.getGrade() << std::endl;
    try
    {
        while (A.getGrade() >= 1)
        {
            std::cout << "\033[34m   Incrementing...\033[0m" << std::endl;
            A.increment(1);
            std::cout << "New grade: " << A.getGrade() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    Bureaucrat B("B", 140);
    std::cout << "-Name: " << B.getName() << std::endl;
    std::cout << "-Grade: " << B.getGrade() << std::endl;
    std::cout << "\033[34m   Decrementing...\033[0m" << std::endl;
    B.decrement(8);
    std::cout << "New grade: " << B.getGrade() << std::endl;
    try
    {
        while (B.getGrade() <= 150)
        {
            std::cout << "\033[34m   Decrementing...\033[0m" << std::endl;
            B.decrement(1);
            std::cout << "New grade: " << B.getGrade() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "   Test: Attempting to create Bureaucrats with invalid grades..." << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    try
    {
        Bureaucrat C("C", 151);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat D("D", 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        B.decrement(1);
    }
    catch(...)
    {
        std::cerr << "Catch-all handler" << std::endl;
    }
    std::cout << std::endl;
}
