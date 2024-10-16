#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

/* T::iterator is a dependent type and needs 'typename' keyword
    for compiler to identify it as a type */
template<typename T>
typename T::iterator easyfind(T &container, int val)
{
    typename T::iterator it = std::find(container.begin(), container.end(), val);
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    return it;
};

#endif