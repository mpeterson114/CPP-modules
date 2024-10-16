#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

/* A vector member variable works best here because we need:
    -Dynamic sizing up to 'N' elements
    -Random access for calculating spans
 */
class Span
{
    private:
        unsigned int _N;
        std::vector<int> _vec;
        Span();
        
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int num);
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif
