#include "RPN.hpp"


RPN::RPN(const std::string& input) {}

RPN::RPN(const RPN& other): _input(other._input), _digits(other._digits) {}

RPN &RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        this->_input = other._input;
        this->_digits = other._digits;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isValidNum(const std::string& token)
{
    //add + or - check here?
    if (token.empty())
        return false;
    std::stringstream ss(token);
    int i;
    char c;

    if (!(ss >> i))
        return false;
    if (ss >> c)
        return false;
    return true;
}

void RPN::calculate()
{

}