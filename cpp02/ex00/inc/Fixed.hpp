#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _fixedPointVal;
        static const int _fracBits = 8;

    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(Fixed const &copy);
        Fixed &operator=(Fixed const &copy);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif