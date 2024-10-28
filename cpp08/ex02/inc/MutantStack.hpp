#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {};
        MutantStack(const MutantStack& other) : std::stack<T>(other) {};
        MutantStack& operator=(const MutantStack& other)
        {
            if (this != &other)
                std::stack<T>::operator=(other);
            return *this;
        }
        ~MutantStack() {};

        /* Creating aliases for the iterators by accessing the iterators within the 
            underlying container type (deque by default) */
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator rev_iterator;

        iterator begin() {return std::stack<T>::c.begin();}
        iterator end() {return std::stack<T>::c.end();}
        rev_iterator rbegin() {return std::stack<T>::c.rbegin();}
        rev_iterator rend() {return std::stack<T>::c.rend();}

        /* Const iterators to prevent user from modifying any stack content 
            while iterating */
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_rev_iterator;

        const_iterator begin() const {return std::stack<T>::c.begin();}
        const_iterator end() const {return std::stack<T>::c.end();}
        const_rev_iterator rbegin() const {return std::stack<T>::c.rbegin();}
        const_rev_iterator rend() const {return std::stack<T>::c.rend();}

};

#endif
