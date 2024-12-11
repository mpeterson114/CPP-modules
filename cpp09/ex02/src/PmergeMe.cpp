#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
        *this = other;
    return *this;
}

PmergeMe::~PmergeMe() {};

void PmergeMe::mergeInsertionVec(std::vector<int> &vec)
{
    int n = vec.size();

    if (n <= 1)
        return;
    
    std::vector<int> higherVals((n + 1) / 2);
    std::vector<int> lowerVals(n / 2, 0);

    for (int i = 0; i < (n / 2); i++)
    {
        if (vec[i * 2] > vec[(i * 2) + 1])
        {
            higherVals[i] = vec[i * 2];
            lowerVals[i] = vec[(i * 2) + 1];
        }
        else
        {
            higherVals[i] = vec[(i * 2) + 1];
            lowerVals[i] = vec[i * 2];
        }
    }
    if (n % 2 == 1)
        higherVals[n / 2] = vec[n - 1];
    mergeInsertionVec(higherVals);

    std::vector<int> main;
    main.push_back(lowerVals[0]);
    for (int i = 0; i < higherVals.size(); i++)
        insertVec(main, higherVals[i], main.size());

    std::vector<int> pend(lowerVals.begin() + 1, lowerVals.end());

    /* Jacobsthal numbers: used in the merging process to determine how many elements from 'pend' 
    should be inserted into the vector 'main' in each iteration */
    
    
}


