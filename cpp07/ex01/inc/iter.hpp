#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T, std::size_t N>
void iter(T& arr, sizeof(arr), T* f())
{
    T i;

    for (i = 0; i < len; i++)
        f(arr[i]);
};


#endif