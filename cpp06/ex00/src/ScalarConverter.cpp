#include "ScalarConverter.hpp"

/* ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
    *this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
    if (this != &copy)
        *this = copy;
    return *this;
}

ScalarConverter::~ScalarConverter() {} */

std::string ScalarConverter::getType(const std::string& input)
{
    std::string type;

    if (input == 'inff' || input == '-inff' || input == '+inff' || input == 'nanf')
        type = PSEUDO_F;
    else if (input == 'inf' || input == '-inf' || input == '+inf' || input == 'nan')
        type = PSEUDO_D;
    else if (len(input) == 1 && !isdigit(input[0]))
        type = CHAR;
    else if (isInt(input))
        type = INT;
    else if (isDouble(input))
        type = DOUBLE;
    else if (isFloat(input))
        type = FLOAT;
    else 
       type = UNKNOWN;
       throw ScalarConverter::UnknownType();
}

/* Exception */
const char *ScalarConverter::UnknownType::what() const throw()
{
    return "\033[38;5;209mUnknown variable type\033[0m"
}

