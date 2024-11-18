#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN 
{
    private:
        std::stack<int> _digits;
        std::string _input;
        RPN();

    public:
        RPN(const std::string& input);
        RPN(const RPN& other);
        RPN &operator=(const RPN& other);
        ~RPN();

        bool isValidNum(const std::string& token);
        int strToInt(const std::string& token);
        void calculate();
};

#endif
