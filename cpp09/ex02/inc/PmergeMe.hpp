#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

class PmergeMe
{
    private:
        template <typename T> void _mergeInsertionSort(T& container, int level);
        template <typename T> void _swapPair(T it, int level);
    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void sortVector(std::vector<unsigned int>& vec);
        void sortDeque(std::deque<unsigned int>& deq);
};



#endif