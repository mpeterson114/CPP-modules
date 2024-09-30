#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cmath>

enum type 
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO_F,
    PSEUDO_D,
    UNDEFINED
};

class ScalarConverter 
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& copy);
        ~ScalarConverter();

        static std::string getType(const std::string& input);
        /* getType() format different from non-static getter functions:
            1. Returns by value rather than 'const &' type: because function is static,
            returning reference to local variable could cause dangling reference once
            function goes out of scope
                -doesn't have access to member variables throughout duration of program
                via instantiation of object

            2. Takes a parameter: doesn't have access to member variables through
            object instantiation, relies on parameter for necessary info
        */

        static bool isInt(const std::string& input);
        static bool isFloat(const std::string& input);
        static bool isDouble(const std::string& input);
        static void displayChar(const std::string& input);
        static void displayInt(const std::string& input);
        static void displayFloat(const std::string& input);
        static void displayDouble(const std::string& input);
        static void displayPseudoFloat(const std::string& input);
        static void displayPseudoDouble(const std::string& input);

        //Exception for unknown variable type??


    public:
        static void convert(const std::string& input);

};

#endif