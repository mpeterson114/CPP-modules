#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "------------------------------------------------------------------------" << std::endl;
    std::cout << "  Test: Able to sign form, grades in valid range to sign and execute... " << std::endl;
    std::cout << "------------------------------------------------------------------------" << std::endl;
    Bureaucrat A("A", 10);
    std::cout << "-Name: " << A.getName() << std::endl;
    std::cout << "-Grade: " << A.getGrade() << std::endl;
    std::cout << "\033[34m   Incrementing...\033[0m" << std::endl;
    A.increment(8);
    std::cout << "-New grade: " << A.getGrade() << std::endl;
    std::cout << std::endl;
    Form abc("abc", 2, 2);
    std::cout << abc << std::endl;
    try
    {
        A.signForm(abc);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << abc << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "  Test: Attempting to sign same form twice... " << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    try
    {
        A.signForm(abc);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "  Test: Unable to sign form, Bureaucrat's grades too low... " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    Bureaucrat B("B", 140);
    std::cout << "-Name: " << B.getName() << std::endl;
    std::cout << "-Grade: " << B.getGrade() << std::endl;
    std::cout << std::endl;
    Form xyz("xyz", 135, 135);
    std::cout << xyz << std::endl;
    try
    {
        B.signForm(xyz);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << xyz << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------------------------" << std::endl;
    std::cout << "  Test: Unable to create forms/Bureaucrats, grades out of valid range...  " << std::endl;
    std::cout << "--------------------------------------------------------------------------" << std::endl;
    try
    {
        Form lmn("lmn", 141, 155);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form lmn("lmn", 141, 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat C("C", 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat C("C", 160);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    // ***TRIAL situations where cannot execute because too low/high*^****


    // std::cout << "Attempting to create Bureaucrats with invalid grades..." << std::endl;
    // try
    // {
    //     Bureaucrat C("C", 151);
    // }
    // catch (const std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // std::cout << std::endl;
    // try
    // {
    //     Bureaucrat D("D", 0);
    // }
    // catch (const std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // std::cout << std::endl;
    // try
    // {
    //     B.decrement(1);
    // }
    // catch(...)
    // {
    //     std::cout << "Catch-all handler" << std::endl;
    // }

}