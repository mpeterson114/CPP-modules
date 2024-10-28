#include <easyfind.hpp>
#include <vector>
#include <list>
#include <deque>

/* -Vector: Best for random access and when the size doesn't change much +
     (contiguous memory storage)
    -List: Good for frequent insertions/deletions at any position but no random access
     (non-contiguous memory storage)
    -Deque: Good for frequent operations at both ends, with decent random access performance
     (segmented memory storage)
*/

int main()
{
    std::cout << "----------------------" << std::endl;
    std::cout << "------- VECTOR -------" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::vector<int> vec;
    std::cout << "\033[34mVector contents: { ";
    for (int i = 1; i <= 10; i++)
    {
        vec.push_back(i);
        std::cout << i << " ";
    }
    std::cout << "}\033[0m" << std::endl;
    std::cout << std::endl;
    
    for (int val = 6; val <= 12; val++)
    {
        try
        {
            std::cout << "Searching for value '" << val << "'..." << std::endl;
            std::vector<int>::iterator it = easyfind(vec, val);
            std::cout << "\033[32m   Found: " << *it << "\033[0m" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\033[35m   Error: " << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "----------------------" << std::endl;
    std::cout << "-------- LIST --------" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::list<int> lst;
    std::cout << "\033[34mList contents: { ";
    for (int i = 1; i <= 10; i++)
    {
        lst.push_back(i);
        std::cout << i << " ";
    }
    std::cout << "}\033[0m" << std::endl;
    std::cout << std::endl;
    
    for (int val = 6; val <= 12; val++)
    {
        try
        {
            std::cout << "Searching for value '" << val << "'..." << std::endl;
            std::list<int>::iterator it = easyfind(lst, val);
            std::cout << "\033[32m   Found: " << *it << "\033[0m" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\033[35m   Error: " << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "-----------------------" << std::endl;
    std::cout << "-------- DEQUE --------" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::deque<int> deq;
    std::cout << "\033[34mDeque contents: { ";
    for (int i = 1; i <= 10; i++)
    {
        deq.push_back(i);
        std::cout << i << " ";
    }
    std::cout << "}\033[0m" << std::endl;
    std::cout << std::endl;
    
    for (int val = 6; val <= 12; val++)
    {
        try
        {
            std::cout << "Searching for value '" << val << "'..." << std::endl;
            std::deque<int>::iterator it = easyfind(deq, val);
            std::cout << "\033[32m   Found: " << *it << "\033[0m" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\033[35m   Error: " << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << std::endl;

    return 0;
}
