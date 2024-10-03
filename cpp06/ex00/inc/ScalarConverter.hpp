#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <exception>

typedef enum e_type 
{
    CHAR,
    NUMBER,
    PSEUDO,
    INVALID
} t_type;

class ScalarConverter 
{
    private:
        explicit ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& copy);
        ~ScalarConverter();

        static std::string input;
        static t_type type;

        /* these member functions don't need param passed, already have
         access to static members*/
        static bool isChar();
        static bool isNumber();
        static bool isPseudo();

        static void printChar();
        static void printNumber();
        static void printPseudo();

    public:
        /* Alias to facilitate use of class throughout code */
        typedef ScalarConverter SC;

        static void convert(const std::string& input);

        static void setType();

        class InvalidType : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif
