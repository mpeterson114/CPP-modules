#include "iter.hpp"

int main()
{
    std::cout << "______ CHAR ARRAY ________" << std::endl;
    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArrSize = sizeof(charArr) / sizeof(charArr[0]);
    std::cout << "Pre-increment array: " << std::endl << "[ ";
    ::iter(charArr, charArrSize, &print);
    std::cout << "]" << std::endl;
    ::iter(charArr, charArrSize, &increment);
    std::cout << "Post-increment array: " << std::endl << "[ ";
    ::iter(charArr, charArrSize, &print);
    std::cout << "]" << std::endl;
    std::cout << std::endl;
    
    std::cout << "______ INT ARRAY ________" << std::endl;
    int numArr[] = {1, 2, 3, 4, 5};
    size_t numArrSize = sizeof(numArr) / sizeof(numArr[0]);
    std::cout << "Pre-increment array: " << std::endl << "[ ";
    ::iter(numArr, numArrSize, print);
    std::cout << "]" << std::endl;
    ::iter(numArr, numArrSize, increment);
    std::cout << "Post-increment array: " << std::endl << "[ ";
    ::iter(numArr, numArrSize, print);
    std::cout << "]" << std::endl;
    std::cout << std::endl;

    std::cout << "______ DOUBLE ARRAY ________" << std::endl;
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArrSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    std::cout << "Pre-increment array: " << std::endl << "[ ";
    ::iter(doubleArr, doubleArrSize, print);
    std::cout << "]" << std::endl;
    ::iter(doubleArr, doubleArrSize, increment);
    std::cout << "Post-increment array: " << std::endl << "[ ";
    ::iter(doubleArr, doubleArrSize, print);
    std::cout << "]" << std::endl;
    std::cout << std::endl;
}