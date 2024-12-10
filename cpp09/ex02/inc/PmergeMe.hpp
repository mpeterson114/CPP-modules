#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <sstream>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void sortVector(std::vector<unsigned int>& vec);
        void sortDeque(std::deque<unsigned int>& deq);
    private:
        template <typename T> void _pairSwap(T it, int level)
        {
            
        }

        template <typename T> void _fordJohnson(T& container, int level)
        {
            typedef typename T::iterator it;

            int numPairs = container.size() / level;
            if (numPairs < 2)
                return ;
            bool isOdd = numPairs % 2 == 1;

            it start = container.begin();
            it last = jump(container.begin(), (level * numPairs));
            it end = jump(last, -(isOdd * level));


        }

};

template <typename T> T jump(T it, int steps)
{
    std::advance(it, steps);
    return it;
}



#endif