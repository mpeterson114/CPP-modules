#include "Span.hpp"

/* Constructors, Overloads & Destructor */
Span::Span(unsigned int N) : _N(N)
{}

Span::Span(const Span& other) : _N(other._N), _vec(other._vec)
{}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->_N = other._N;
        this->_vec = other._vec;
    }
    return *this;
}

Span::~Span() {}

/* Member Functions */
void Span::addNumber(int num)
{
    if (this->_vec.size() == this->_N)
        throw std::runtime_error("Vector is already full");
    this->_vec.push_back(num);
}

unsigned int Span::longestSpan()
{
    if (this->_vec.size() <= 1)
        throw std::runtime_error("No detectable span in vector");
    
    std::sort(this->_vec.begin(), this->_vec.end());
    return this->_vec.back() - this->_vec.front();
}

unsigned int Span::shortestSpan()
{
    if (this->_vec.size() <= 1)
        throw std::runtime_error("No detectable span in vector");

    else if (this->_vec.size() == 2)
        return this->longestSpan();
    
    std::sort(this->_vec.begin(), this->_vec.end());
    size_t i = 1;
    unsigned int shortest = this->_vec[i] - this->_vec[i - 1];

    for (i = 2; i < this->_vec.size(); i++)
    {
        unsigned int diff = this->_vec[i] - this->_vec[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

void Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if ((unsigned int) std::distance(begin, end) >= (this->_N - this->_vec.size()))
        throw std::runtime_error("Elements can't all fit in vector");
    while (begin != end && this->_vec.size() < _N)
    {
        this->_vec.push_back(*begin);
        ++begin;
    }
}
