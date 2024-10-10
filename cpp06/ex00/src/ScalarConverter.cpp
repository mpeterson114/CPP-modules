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

std::string ScalarConverter::input;
t_type ScalarConverter::type;
bool ScalarConverter::hasDecimal = false;

void ScalarConverter::convert(const std::string& input)
{
    if (input.length() == 0)
        throw SC::InvalidType();
    
    SC::input = input;
    SC::setType();

    switch (SC::type)
    {
        case CHAR: 
            SC::printChar();
            break;
        case NUMBER:
            SC::printNumber();
            break;
        case PSEUDO:
            SC::printPseudo();
            break;
        case INVALID:
            throw SC::InvalidType();
    }
}

void ScalarConverter::setType()
{
    if (SC::isChar())
        SC::type = CHAR;
    else if (SC::isNumber())
        SC::type = NUMBER;
    else if (SC::isPseudo())
        SC::type = PSEUDO;
    else
        SC::type = INVALID;
}

bool ScalarConverter::isChar()
{
    if (SC::input.length() == 1 && !isdigit(SC::input[0]))
        return true;
    return false;
}

bool ScalarConverter::isNumber()
{
    size_t i = 0;
    SC::hasDecimal = false;

    if (SC::input[i] == '+' || SC::input[i] == '-')
        i++;
    if (!isdigit(SC::input[i]) && SC::input[i] != '.')
        return false;
    for (; i < SC::input.length(); i++)
    {
        if (SC::input[i] == '.')
        {
            if (SC::hasDecimal)
                return false;
            SC::hasDecimal = true;
        }
        else if (!isdigit(SC::input[i]))
            break;
    }
    if (SC::input[i] == 'f' && (isdigit(SC::input[i - 1]) || SC::input[i - 1] == '.'))
        i++;
    return i == SC::input.length();
}
        
bool ScalarConverter::isPseudo()
{
    if (SC::input == "+inff" || SC::input == "-inff"
        || SC::input == "nanf" || SC::input == "+inf" 
        || SC::input == "-inf" || SC::input == "nan")
        return true;
    return false;
}

void ScalarConverter::printChar()
{
    char c = SC::input[0];
    
    if (isprint(c))
        std::cout << "Char: '" << c << "'" << std::endl;
    else
        std::cout << "Char: Non displayable" << std::endl;
    std::cout << "Int: " << static_cast<int>(c) << std::endl;
    std::cout << "Float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "Double: " << static_cast<double>(c) <<".0" << std::endl;
}

void ScalarConverter::printNumber()
{
    double number = static_cast<double>(strtod(SC::input.c_str(), NULL));

    if (number > std::numeric_limits<double>::max() || number < -std::numeric_limits<double>::max())
    {
        std::cout << "Char: Impossible (outside valid char range)" << std::endl;
        std::cout << "Int: Impossible (outside valid int range)" << std::endl;
        std::cout << "Float: Impossible (outside valid float range)" << std::endl;
        std::cout << "Double: Impossible (outside valid double range)" << std::endl;
        return;
    }

    if (number > std::numeric_limits<char>::max() || number < std::numeric_limits<char>::min())
        std::cout << "Char: Impossible (outside valid char range)" << std::endl;
    else if (number <= std::numeric_limits<char>::max() || number >= std::numeric_limits<char>::min())
    {
        if (!isprint(static_cast<char>(number)))
            std::cout << "Char: Non displayable" << std::endl;
        else
            std::cout << "Char: '" << static_cast<char>(number) << "'" << std::endl;
    }
    if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
        std::cout << "Int: Impossible (outside valid int range)" << std::endl;
    else
        std::cout << "Int: " << static_cast<int>(number) << std::endl;
    
    if (number > std::numeric_limits<float>::max() || number < -std::numeric_limits<float>::max())
        std::cout << "Float: Impossible (outside valid float range)" << std::endl;
    else
    {
        float f = static_cast<float>(number);
        if (f - floorf(f) == 0)
            std::cout << "Float: " << f << ".0f" << std::endl;
        else
            std::cout << "Float: " << f << "f" << std::endl;
    }
    if (number - floor(number) == 0)
        std::cout << "Double: " << static_cast<double>(number) << ".0" << std::endl;
    else
        std::cout << "Double: " << static_cast<float>(number) << std::endl;
    
}

void ScalarConverter::printPseudo()
{
    std::cout << "Char: Impossible (outside valid char range)" << std::endl;
    std::cout << "Int: Impossible (outside valid int range)" << std::endl;

    if (SC::input == "+inff" || SC::input == "+inf")
    {
        std::cout << "Float: +inff" << std::endl;
        std::cout << "Double: +inf" << std::endl;
    }
    else if (SC::input == "-inff" || SC::input == "-inf")
    {
        std::cout << "Float: -inff" << std::endl;
        std::cout << "Double: -inf" << std::endl;
    }
    else if (SC::input == "nanf" || SC::input == "nan")
    {
        std::cout << "Float: nanf" << std::endl;
        std::cout << "Double: nan" << std::endl;
    }
}

const char *ScalarConverter::InvalidType::what() const throw()
{
    return "\033[38;5;209mInvalid scalar conversion\033[0m";
}

