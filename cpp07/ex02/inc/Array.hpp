#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array
{
    private:
        unsigned int _size;
        T* _data;

    public:
    /* (new T[0] preferred to 'NULL', avoids having to check if _data is NULL
     and ensures that valid memory is always allocated (even if empty)) */
        Array() : _size(0), _data(new T[0]) 
        {
            if (!this->_data)
                throw std::bad_alloc();
        };
        
        Array(unsigned int n) : _size(n), _data(new T[n])
        {
            std::cout << "Array parameterized constructor called" << std::endl;
            if (!this->_data)
                throw std::bad_alloc();
        }; 

        Array(const Array& other) : _size(other._size), _data(new T[other._size])
        {
            if (!this->_data)
                throw std::bad_alloc();
            while (other->_data)
                
            
        }

        Array &operator=(const Array& other) 
        {
            if (this != &other)
            {
                _size = other._size;
                _data = other._data;
            }
            return *this;
        }

        ~Array();

        unsigned int size() const 
        {
            return this->_size;
        }

};




#endif