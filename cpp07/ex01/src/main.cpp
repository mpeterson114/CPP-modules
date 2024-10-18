#include "iter.hpp"

int main()
{
    std::cout << "______ CHAR ARRAY ________" << std::endl;
    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArrSize = sizeof(charArr) / sizeof(charArr[0]);
    std::cout << "Pre-increment array: " << std::endl << "[ ";
    ::iter(charArr, charArrSize, print<char>);
    std::cout << "]" << std::endl;
    ::iter(charArr, charArrSize, increment<char>);
    std::cout << "Post-increment array: " << std::endl << "[ ";
    ::iter(charArr, charArrSize, print<char>);
    std::cout << "]" << std::endl;
    std::cout << "Post-capitalization array: " << std::endl << "[ ";
    ::iter(charArr, charArrSize, capitalizeChar<char>);
    ::iter(charArr, charArrSize, print<char>);
    std::cout << "]" << std::endl;
    std::cout << std::endl;
    
    std::cout << "______ INT ARRAY ________" << std::endl;
    int numArr[] = {1, 2, 3, 4, 5};
    size_t numArrSize = sizeof(numArr) / sizeof(numArr[0]);
    std::cout << "Pre-increment array: " << std::endl << "[ ";
    ::iter(numArr, numArrSize, print<int>);
    std::cout << "]" << std::endl;
    ::iter(numArr, numArrSize, increment<int>);
    std::cout << "Post-increment array: " << std::endl << "[ ";
    ::iter(numArr, numArrSize, print<int>);
    std::cout << "]" << std::endl;
    std::cout << std::endl;

    std::cout << "______ DOUBLE ARRAY ________" << std::endl;
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArrSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    std::cout << "Pre-increment array: " << std::endl << "[ ";
    ::iter(doubleArr, doubleArrSize, print<double>);
    std::cout << "]" << std::endl;
    ::iter(doubleArr, doubleArrSize, increment<double>);
    std::cout << "Post-increment array: " << std::endl << "[ ";
    ::iter(doubleArr, doubleArrSize, print<double>);
    std::cout << "]" << std::endl;
    std::cout << std::endl;

    std::cout << "______ STRING ARRAY ________" << std::endl;
    const char *strArr[] = {"hey", "hi", "hello", "whatup"};
    size_t strArrSize = sizeof(strArr) / sizeof(strArr[0]);
    std::cout << "Print string array: " << std::endl << "[ ";
    ::iter(strArr, strArrSize, print<const char*>);
    std::cout << "]" << std::endl;
    std::cout << std::endl;
}
