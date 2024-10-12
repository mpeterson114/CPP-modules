#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <cstddef>

template<typename T>
void iter(T* arr, size_t len, void (*func)(T&))
{
    size_t i;

    if (!arr || !func)
        return ;
    for (i = 0; i < len; i++)
        func(arr[i]);
};

template<typename T>
void increment(T& value)
{
    value += 1;
};

template<typename T>
void print(T& value)
{
    std::cout << value << " ";
};


#endif