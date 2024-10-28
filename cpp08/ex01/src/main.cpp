#include "Span.hpp"
#include <vector>

int main()
{
    std::cout << "------------------------------" << std::endl;
    std::cout << "-------- FROM SUBJECT --------" << std::endl;
    std::cout << "------------------------------" << std::endl;
    Span sp = Span(5);
    sp.addNumber(9);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(6);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "-------- EMPTY & 1-NUMBER SPAN TESTS --------" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "  -> Empty Span Created <-  " << std::endl;
    Span empty(0);
    try
    {
        std::cout << "Attempting to add number..." << std::endl;
        empty.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[35m" << e.what() << "\033[0m" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "  -> Creating Span of 1 number <-  " << std::endl;
    Span small(1);
    std::cout << "Adding number <-42>..." << std::endl;
    small.addNumber(-42);
    std::cout << "Adding another number <-43>......" << std::endl;
    try
    {
        small.addNumber(-43);
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[35m" << e.what() << "\033[0m" << std::endl;
    }
    std::cout << "Shortest Span: " << std::endl;
    try
    {
        small.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[35m" << e.what() << "\033[0m" << std::endl;
    }
    std::cout << "Longest Span:" << std::endl;
    try
    {
        small.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[35m" << e.what() << "\033[0m" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "-------- MORE TESTS --------" << std::endl;
    std::cout << "----------------------------" << std::endl;
    Span medium(5);
    std::cout << "Creating span 'medium' with max of 5 numbers <5, 20, 15, 10>" << std::endl;
    medium.addNumber(5);
    medium.addNumber(20);
    medium.addNumber(15);
    medium.addNumber(10);
    std::cout << "Shortest span: " << medium.shortestSpan() << std::endl;
    std::cout << "Longest span: " << medium.longestSpan() << std::endl;
    std::cout << std::endl;
    std::cout << "Adding <-50> to 'medium'...." << std::endl;
    medium.addNumber(-50);
    std::cout << "Shortest span: " << medium.shortestSpan() << std::endl;
    std::cout << "Longest span: " << medium.longestSpan() << std::endl;
    std::cout << std::endl;

    std::cout << "--------------------------------------" << std::endl;
    std::cout << "-------- FILL LARGE SPAN TEST --------" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Creating Span 'large' with 10000 numbers" << std::endl;
    Span large(10000);
    std::vector<int> temp;
    for (int i = 1; i < 10000; i++)
        temp.push_back(i * 5);
    try
    {
        large.fillSpan(temp.begin(), temp.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[35m" << e.what() << "\033[0m" << std::endl;
    }
    try
    {
        std::cout << "Shortest span: " << large.shortestSpan() << std::endl;
        std::cout << "Longest span: " << large.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[35m" << e.what() << "\033[0m" << std::endl;
    }
    std::cout << std::endl;
    try
    {
        std::cout << "Adding <50001> to 'large'..." << std::endl;
        large.addNumber(50001);
        std::cout << "Shortest span: " << large.shortestSpan() << std::endl;
        std::cout << "Longest span: " << large.longestSpan() << std::endl;
        std::cout << std::endl;
        std::cout << "Adding <50002> to 'large'..." << std::endl;
        large.addNumber(50002);
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[35m" << e.what() << "\033[0m" << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
