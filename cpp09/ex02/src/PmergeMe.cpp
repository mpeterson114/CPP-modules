#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

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

PmergeMe::~PmergeMe() {}

void PmergeMe::mergeInsertionVec(std::vector<int> &vec)
{
    int n = vec.size();

    if (n <= 1)
        return;
    
    std::vector<int> higherVals((n + 1) / 2);
    std::vector<int> lowerVals((n) / 2, 0);

    for (int i = 0; i < (n / 2); ++i)
    {
        if (vec[i * 2] > vec[2 * i + 1])
        {
            higherVals[i] = vec[i * 2];
            lowerVals[i] = vec[2 * i + 1];
        }
        else
        {
            higherVals[i] = vec[2 * i + 1];
            lowerVals[i] = vec[i * 2];
        }
    }
    if (n % 2 == 1)
        higherVals[n / 2] = vec[n - 1];
    mergeInsertionVec(higherVals);

    std::vector<int> main;
    main.push_back(lowerVals[0]);
    for (size_t i = 0; i < higherVals.size(); ++i)
        _insertVec(main, higherVals[i], main.size());

    std::vector<int> pend(lowerVals.begin() + 1, lowerVals.end());

    /* Jacobsthal numbers: used to determine how many elements from 'pend' should be inserted into the 
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
    
    static u_int64_t jacobsthalVals[63] = {
            2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
			2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
			1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
			178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
			11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
			366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
			11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
			375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
			6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
			96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
			1537228672809129216u, 3074457345618258432u, 6148914691236516864u};
        
    size_t jNum = 0;
    size_t pendInd = 0;
    while (pendInd < pend.size() && jNum < 63)
    {
        for (size_t j = 0; j < jacobsthalVals[jNum] && pendInd < pend.size(); ++j)
        {
            _insertVec(main, pend[pendInd], main.size());
            ++pendInd;
        }
        ++jNum;
    }
    
    for (size_t i = 0; i < main.size(); ++i)
        vec[i] = main[i];
}

void PmergeMe::mergeInsertionList(std::list<int> &lst)
{
    int n = lst.size();

    if (n <= 1)
        return ;

    std::list<int> higherVals;
    std::list<int> lowerVals;

    std::list<int>::iterator it = lst.begin();
    for (int i = 0; i < (n / 2); ++i)
    {
        int first = *it++;
        int second = *it++;
        if (first > second)
        {
            higherVals.push_back(first);
            lowerVals.push_back(second);
        }
        else
        {
            higherVals.push_back(first);
            lowerVals.push_back(second);
        }
    }
    if (n % 2 == 1)
        higherVals.push_back(*it);
    
    mergeInsertionList(higherVals);

    std::list<int> main;
    main.push_back(lowerVals.front());
    lowerVals.pop_front();

    for (std::list<int>::iterator li = higherVals.begin(); li != higherVals.end(); ++li)
        _insertList(main, *li);

    std::list<int> pend(lowerVals.begin(), lowerVals.end());
    static u_int64_t jacobsthalVals[63] = {
			2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
			2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
			1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
			178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
			11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
			366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
			11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
			375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
			6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
			96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
			1537228672809129216u, 3074457345618258432u, 6148914691236516864u};

    size_t jNum = 0;
    std::list<int>::iterator pendInd = pend.begin();
    while (pendInd != pend.end() && jNum < 63)
    {
        for (size_t j = 0; j < jacobsthalVals[jNum] && pendInd != pend.end(); ++j)
        {
            _insertList(main, *pendInd);
            ++pendInd;
        }
        ++jNum;
    }
    lst = main;
}

void PmergeMe::_insertVec(std::vector<int> &vec, int value, int higher)
{
    int lower = 0;

    while (lower < higher)
    {
        int mid = lower + (higher - lower) / 2;

        if (vec[mid] < value)
            lower = mid + 1;
        else
            higher = mid;
    }
    vec.insert(vec.begin() + lower, value);
}

void PmergeMe::_insertList(std::list<int> &lst, int value)
{
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator end = lst.end();
    while (it != end && *it < value)
        ++it;
    lst.insert(it, value);
}








