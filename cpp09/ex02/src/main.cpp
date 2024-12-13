#include "PmergeMe.hpp"

bool isNumber(const char *str)
{
    if (str == NULL || strlen(str) == 0)
        return false;

    std::istringstream iss(str);
    int n;
    char c;
    if (iss >> n)
    {
        if (iss >> c)
        {
            return false;
        }
        return true;
    }
    return false;
}

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
        const char *arg = argv[i];
        if (!isNumber(arg))
        {
            std::cerr << "Error: Invalid argument: " << arg << std::endl;
            return 1;
        }

        std::istringstream iss(arg);
        int n;
        iss >> n; 
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

/* Ford-Johnson algorithm: combines merge-sort (recursively sorting larger elements via divide-and-conquer) and
    an optimized insertion-sort (to insert smaller values into sorted structure) with a focus on minimizing the 
    number of comparisons made at each step (Jacobsthal sequence used for this) 
_________________________________________________________________________________________________________________

1. Input array is recursively divided into 2 subarrays at each level by comparing adjacent pairs of elements
    -higher value -> higherVals subarray
    -lower value -> lowerVals subarray
    * If there is an unpaired odd element, it's added to the higherVals subarray.
    -Recursion continues until base case (n <= 1) is hit and unwinding process begins
        - At this point, higherVals[] subarray for each level is now sorted from previous level and lowerVals[] at each
            level is how we left it

2. Create a sub-container 'main' out of the first element of the lowerVals[] subarray at each level
3. Relevant 'insert' function is called to add sorted higherVals[] elements to 'main' in order via binary insertion
4. Remaining lowerVals are stored in a 'pend' sub-container
5. Then, helper array 'jacobsthalVals[]' is used to determine insertion order of 'pend' elements into 'main'
container
6. 'Main' container, once sorted, is copied back to the original container (vector or list)
___________________________________________________________________________________________________________________

Jacobsthal numbers: used to determine how many elements from 'pend' should be inserted into the 
    vector 'main' in each iteration while minimizing the number of comparisons made
        -Current Jacobsthal # (J) - previous Jacobsthal # in sequence (J - 1) is how we determine the number
            of elements from pend[] to insert into main[] at each step.
        - jacobsthalVals[] array contains pre-calculated # of elements to insert for each Jacobsthal number
        - We exploit binary search's efficiency by dividing elements into groups that fit binary search's halving
            process
            - Multiple elements inserted at a time, reduces # of comparisons needed at each step 
                - ** (2^(k+1) - 1) : binary search range at each level
                -Jacobsthal number (J) = Starting point & how many elements to insert from that point (J - J(prev))
                -K = index of J number we're using -> used to calc. binary search range (rather than having to search 
                thru all elements) 
        - Max array size of 63: beyond this values get too large to safely fit into 64-bit integer ranges
        -'u' suffix (unsigned int): prevents unwanted overflow or negative values */
