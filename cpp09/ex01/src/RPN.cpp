#include "RPN.hpp"

RPN::RPN(const std::string& input) : _input(input) {}

RPN::RPN(const RPN& other): _digits(other._digits), _input(other._input) {}

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
    int i;
    char c;

    if (!(ss >> i))
        return false;
    if (ss >> c)
        return false;
    return true;
}

int RPN::strToInt(const std::string& token)
{
    int val;
    std::stringstream ss(token);
    ss >> val;
    if (ss.fail())
        throw std::invalid_argument("Invalid number: " + token);
    return (val);
}

void RPN::calculate()
{
    std::stringstream ss(this->_input);
    std::string token;
    bool hasOperator = false;

    while (ss >> token)
    {
        // If token encountered is a number
        if (isValidNum(token))
        {
            int val = strToInt(token);
            if (val > 9 || val < 0)
                throw std::invalid_argument("Number outside valid range: " + token);
            this->_digits.push(val);
        }
        // If token encountered is an operator
        else if (token.length() == 1 && std::string("+-*/").find(token) != std::string::npos)
        {
            hasOperator = true;
            if (this->_digits.size() < 2)
                throw std::runtime_error("Need at least 2 values in stack before operator: " + token);
            int second = this->_digits.top();
            this->_digits.pop();
            int first = this->_digits.top();
            this->_digits.pop();
            char op = token[0];
            switch(op) 
            {
                case '+':
                    this->_digits.push(first + second);
                    break ;
                case '-':
                    this->_digits.push(first - second);
                    break ;
                case '*':
                    this->_digits.push(first * second);
                    break ;
                case '/':
                    if (second == 0)
                        throw std::invalid_argument("Cannot divide by 0");
                    this->_digits.push(first / second);
                    break ;
                default:
                    throw std::invalid_argument("Invalid operator passed: " + token);
            }
        }
        else
            throw std::invalid_argument("Invalid token: " + token);
    }
    if (this->_digits.size() == 1 && hasOperator == false)
        throw std::invalid_argument("Need at least one operator '+-*/'");
    if (this->_digits.size() != 1)
        throw std::runtime_error("Invalid RPN expression");
    std::cout << this->_digits.top() << std::endl;
}