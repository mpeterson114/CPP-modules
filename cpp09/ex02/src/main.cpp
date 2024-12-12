#include "PmergeMe.hpp"

/* Recursively divide into pairs of numbers, pairs of pairs of numbers, 
pairs of pairs of pairs of numbers... etc, and sort them by the biggest number, 
until we can't form any pair anymore. If there is an unpaired odd element, leave it be.

Create a sequence (also referred to as S or the main chain) 
out of the smallest element of the smallest pair (b1) and the rest of as. If the first step was done
correctly, this sequence will be sorted. Create the sequence that consists of the rest 
of bs (also referred to as the pend).

Binary insert the elements from the pend into the main, in the order based on Jacobsthal numbers.

If we can't insert elements into the main using Jacobsthal numbers anymore, we insert them normally, in order, 
using binary insertion.

Insert the odd element that didn't fit into any pair.  
*/

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: Usage: " << argv[0] << " <list of positive numbers>" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::list<int> lst;

    for (int i = 1; i < argc; i++)
    {
        int n = std::atoi(argv[i]);
        if (n < 0)
        {
            std::cerr << "Error: values must be positive numbers" << std::endl;
            return 1;
        }
        vec.push_back(n);
        lst.push_back(n);
    }
    PmergeMe pm;
    std::cout << "Before: ";
    std::ostream_iterator<int> output_it(std::cout, " ");
    std::copy(vec.begin(), vec.end(), output_it);
    std::cout << std::endl;
    
    const clock_t startTimeVector = clock();
    pm.mergeInsertionVec(vec);
    const clock_t timeVec = static_cast<double>(clock() - startTimeVector) / CLOCKS_PER_SEC * 1000000;

    const clock_t startTimeList = clock();
    pm.mergeInsertionList(lst);
    const clock_t timeList = static_cast<double>(clock() - startTimeList) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    std::ostream_iterator<int> output_iter(std::cout, " ");
    std::copy(lst.begin(), lst.end(), output_iter);
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector container: " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << lst.size() << " elements with std::list container: " << timeList << " us" << std::endl;
}


