#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
    private:
        

    public:
        MutantStack() : std::stack<T>();
        MutantStack(const MutantStack& other) : std::stack<T>(other);
        MutantStack& operator=(const MutantStack& other) 
        {
            if (this != &other)
                std::stack<T>::operator=(other);
            return *this;
        }
        ~MutantStack();

        typedef typename std::stack


        //push()
        //pop()
        bool empty() const;
        size_type size() const;
        reference top();

};

#endif