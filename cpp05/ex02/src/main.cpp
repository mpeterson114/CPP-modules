#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* Create Bureaucrats (one ok grades, others too low/high) and each version of Forms 
-Test to try and create AForm object (can't because abstract)
-Print Info of each form w/ overload
-Sign forms failure (1 w/ each form)
-Sign forms success 
-Exec forms failure (1 b/c not signed, 1 b/c wrong grades)
-Exec forms success
    -print Shrubbery file in SCF test */


int main()
{
    std::cout << "\033[34m------------------------------------\033[0m" << std::endl;
    std::cout << "\033[34m  Creating Bureaucrats and Forms... \033[0m" << std::endl;
    std::cout << "\033[34m------------------------------------\033[0m" << std::endl;
    Bureaucrat A("A", 10);
    Bureaucrat B("B", 40);
    Bureaucrat C("C", 135);
    std::cout << std::endl;
    ShrubberyCreationForm scf("SCFTarget");
    RobotomyRequestForm rrf("RRFTarget");
    PresidentialPardonForm ppf("PPFTarget");
    // AForm test("Test", 1, 1);    // won't compile abstract class object
    std::cout << std::endl;

    std::cout << "\033[34m-----------------------------------\033[0m" << std::endl;
    std::cout << "\033[34m        Bureaucrat Grades          \033[0m" << std::endl;
    std::cout << "\033[34m-----------------------------------\033[0m" << std::endl;
    std::cout << A << std::endl;
    std::cout << B << std::endl;
    std::cout << C << std::endl;
    std::cout << std::endl;

    std::cout << "\033[34m-------------------------------------\033[0m" << std::endl;
    std::cout << "\033[34m        SCF: Sign & Execute          \033[0m" << std::endl;
    std::cout << "\033[34m-------------------------------------\033[0m" << std::endl;
    std::cout << scf << std::endl;
    std::cout << "Bureaucrat C (grade: " << C.getGrade() << ") attempting to sign and execute... " << std::endl;
    try
    {
        scf.beSigned(C);
        scf.execute(C);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "\033[34m-------------------------------------\033[0m" << std::endl;
    std::cout << "\033[34m        RRF: Sign & Execute          \033[0m" << std::endl;
    std::cout << "\033[34m-------------------------------------\033[0m" << std::endl;
    std::cout << rrf << std::endl;
    std::cout << "Bureaucrat C (grade: " << C.getGrade() << ") attempting to sign and execute... " << std::endl;
    try
    {
        rrf.beSigned(C);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Bureaucrat B (grade: " << B.getGrade() << ") attempting to sign and execute... " << std::endl;
    try
    {
        rrf.beSigned(B);
        rrf.execute(B);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "\033[34m-------------------------------------\033[0m" << std::endl;
    std::cout << "\033[34m        PPF: Sign & Execute          \033[0m" << std::endl;
    std::cout << "\033[34m-------------------------------------\033[0m" << std::endl;
    std::cout << ppf << std::endl;
    std::cout << "Bureaucrat B (grade: " << B.getGrade() << ") attempting to sign... " << std::endl;
    try
    {
        ppf.beSigned(B);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Bureaucrat A (grade: " << A.getGrade() << ") attempting to sign... " << std::endl;
    try
    {
        ppf.beSigned(A);
        if (ppf.getIsSigned())
            std::cout << "-> PPF Signed!" << std::endl;
        else
            std::cout << "-> Unable to sign PPF" << std::endl;
        std::cout << std::endl;
        std::cout << "Bureaucrat A (grade: " << A.getGrade() << ") attempting to execute... " << std::endl;
        ppf.execute(A);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Incrementing..." << std::endl;
    A.increment(5);
    std::cout << "Bureaucrat " << A.getName() << " new grade: " << A.getGrade() << std::endl;
    std::cout << std::endl;
    std::cout << "Bureaucrat A (grade: " << A.getGrade() << ") attempting to sign and execute... " << std::endl;
    try
    {
        ppf.beSigned(A);
        ppf.execute(A);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
}