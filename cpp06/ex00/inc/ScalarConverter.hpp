#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

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

        static const std::string& getType();


    public:
        static void convert(const std::string& input);

};

#endif