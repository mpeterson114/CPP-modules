#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <list>
#include <iterator>
#include <sstream>
#include <cstring>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void mergeInsertionVec(std::vector<int> &vec);
        void mergeInsertionList(std::list<int> &lst);

    private:
        void _insertVec(std::vector<int> &vec, int value, int end);
        void _insertList(std::list<int> &lst, int value);
};

#endif
