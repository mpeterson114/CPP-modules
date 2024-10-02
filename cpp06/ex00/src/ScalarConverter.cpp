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

bool ScalarConverter::isInt(const std::string& input)
{
    size_t i;
    if (input[i] == '+' || input[i] == '-')
        i++;
    for (i = 0; i < input.length(); i++)
    {
        if (!isdigit(input[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& input)
{
    size_t i;
    bool hasDecimal = false;

    if (input[i] == '+' || input[i] == '-')
        i++;
    for (i = 0; i < input.length(); i++)
    {
        if (input[i] == '.' && !hasDecimal)
            hasDecimal = true;
        else if (input[i] == '.' && hasDecimal == true)
            return false;
        else if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
            return false;
        i++;
    }
    if (input[input.length() - 1] != 'f')
        return false;
    return true;
}

bool ScalarConverter::isDouble(const std::string& input)
{
    size_t i;
    bool hasDecimal = false;

    if (input[i] == '+' || input[i] == '-')
        i++;
    for (i = 0; i < input.length(); i++)
    {
        if (input[i] == '.' && !hasDecimal)
            hasDecimal = true;
        else if (input[i] == '.' && hasDecimal == true)
            return false;
        else if (!isdigit(input[i]) && input[i] != '.')
            return false;
        i++;
    }
    return true;
}

/* Overflow/Underflow checks primarily necessary when converting from a larger
    data type to a smaller one 
    -When displaying 'char' values, do have to check if value is printable or not */

void ScalarConverter::displayChar(const std::string& input)
{
    char c = input[0];
    
    if (isprint(c))
        std::cout << "Char: '" << c << "'" << std::endl;
    else
        std::cout << "Char: Non-displayable" << std::endl;
    std::cout << "Int: " << static_cast<int>(c) << std::endl;
    std::cout << "Float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "Double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::displayInt(const std::string& input)
{
    double i;  // used to store the number converted from a string, can accommodate range of values
    std::stringstream ss(input);  // creates stringstream object 'ss' and initializes with 'input'. 
                    //Allows you to treat the string as a stream, similar to how you would read from standard input.
    ss >> i;  // reads from ss (input), converts into specified type (double) and stores in i

    if (isprint(static_cast<char>(i)) && i >= std::numeric_limits<char>::min() 
        && i <= std::numeric_limits<char>::max())
        std::cout << "Char: '" << i << "'" << std::endl;
    else
        std::cout << "Char: Non-displayable" << std::endl;

    if (i < std::numeric_limits<int>::min())
        std::cout << "Int: Underflow, outside valid range for 'int'" << std::endl;
    else if (i > std::numeric_limits<int>::max())
        std::cout << "Int: Overflow, outside valid range for 'int'" << std::endl;
    else
        std::cout << "Int: " << static_cast<int>(i) << std::endl;

    if (i < std::numeric_limits<float>::min())
        std::cout << "Float: Underflow, outside valid range for 'float'" << std::endl;
    else if (i > std::numeric_limits<float>::max())
        std::cout << "Float: Overflow, outside valid range for 'float'" << std::endl;
    else
        std::cout << "Float: " << static_cast<float>(i) << ".0f" << std::endl;
        std::cout << "Double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::displayFloat(const std::string& input)
{

}

void ScalarConverter::displayDouble(const std::string& input)
{

}
        static void displayPseudoFloat(const std::string& input);
        static void displayPseudoDouble(const std::string& input);

std::string ScalarConverter::getType(const std::string& input)
{
    std::string type;

    if (input == "inff" || input == "-inff" || input == "+inff" || input == "nanf")
        type = PSEUDO_F;
    else if ((input == "inf") || input == "-inf" || input == "+inf" || input == "nan")
        type = PSEUDO_D;
    else if (input.length() == 1 && !isdigit(input[0]))
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
    return "\033[38;5;209mUnknown variable type\033[0m";
}

