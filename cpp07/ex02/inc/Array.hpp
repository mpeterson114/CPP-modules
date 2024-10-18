#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

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
            /*std::cout << "Array parameterized constructor called" << std::endl;*/
            if (!this->_data)
                throw std::bad_alloc();
        }; 

        Array(const Array& other) : _size(other._size), _data(new T[other._size])
        {
            /*std::cout << "Array copy constructor called" << std::endl;*/
            if (!this->_data)
                throw std::bad_alloc();
            for (size_t i = 0; i < _size; i++)
                this->_data[i] = other._data[i];
        }

        Array& operator=(const Array& other) 
        {
            /*std::cout << "copy assignment operator called" << std::endl;*/
            if (this != &other)
            {
                if (this->_data)
                    delete[] this->_data;
                this->_size = other._size;
                this->_data = new T[other._size];
                if (!this->_data)
                    throw std::bad_alloc();
                for (size_t i = 0; i < _size; i++)
                    this->_data[i] = other._data[i];
            }
            return *this;
        }

        ~Array() 
        {
            if (this->_data)
                delete[] this->_data;
        }
        
        T& operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::out_of_range("\033[35mIndex out of range\033[0m");
            return _data[index];
        }

        const T& operator[](unsigned int index) const
        {
            if (index >= _size)
                throw std::out_of_range("\033[35mIndex out of range\033[0m");
            return _data[index];
        }

        unsigned int size() const 
        {
            return this->_size;
        }
};

#endif
