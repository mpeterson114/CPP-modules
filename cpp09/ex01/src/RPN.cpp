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
    if (token.empty())
        return false;
    std::stringstream ss(token);
    


}

void RPN::calculate()
{

}