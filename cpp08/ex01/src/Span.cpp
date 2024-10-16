#include "Span.hpp"

/* Constructors, Overloads & Destructor */
Span::Span(unsigned int N) : _N(N)
{}

Span::Span(const Span& other) : _N(other._N)
{
    
}

Span& Span::operator=(const Span& other)
{

}

Span::~Span()
{

}

/* Member Functions */
void Span::addNumber(int num)
{

}

unsigned int shortestSpan();
unsigned int longestSpan();
void fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end);