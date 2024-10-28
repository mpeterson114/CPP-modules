#include "MutantStack.hpp"
#include <stack>
#include <list>

/* Stack: LIFO (last in first out)- most recently added element
    is the first to be removed 
    - Elements can only be accessed by pushing to or popping from 
    the top of the stack (no way to iterate through)
    
    -We can add iterator functionality to our custom MutantStack 
    class by accessing the underlying container structure (deque in
    the case of stack) through the protected 'c' member variable */

int main()
{
    std::cout << "\033[34m-----------------------------------\033[0m" << std::endl;
    std::cout << "\033[34m-------- MUTANTSTACK TESTS --------\033[0m" << std::endl;
    std::cout << "\033[34m-----------------------------------\033[0m" << std::endl;
    MutantStack<int> myStack;
    std::cout << "    Pushing [1, 2, 3, 4, 5]... " << std::endl;
    std::cout << std::endl;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    std::cout << "\033[32m_______ ITERATORS (MUTANTSTACK) ________\033[0m" << std::endl;
    std::cout << "My Mutant Stack: " << std::endl;
    for (MutantStack<int>::iterator it = myStack.begin(); it != myStack.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "Reverse iteration: " << std::endl;
    for (MutantStack<int>::rev_iterator rit = myStack.rbegin(); rit != myStack.rend(); rit++)
        std::cout << *rit << " ";
    std::cout << std::endl;
    std::cout << "Const iterator (forward): " << std::endl;
    for (MutantStack<int>::const_iterator cit = myStack.begin(); cit != myStack.end(); cit++)
        std::cout << *cit << " ";
    std::cout << std::endl;
    std::cout << "Const iterator (reverse): " << std::endl;
    for (MutantStack<int>::const_rev_iterator crit = myStack.rbegin(); crit != myStack.rend(); crit++)
        std::cout << *crit << " ";
    std::cout << std::endl;
    // std::cout << "    Modify with const iterator (won't compile)..." << std::endl;
    // for (MutantStack<int>::const_rev_iterator crit = myStack.rbegin(); crit != myStack.rend(); crit++)
    // {
    //     std::cout << *crit << " ";
    //     (*crit) = 42;
    // }
    std::cout << std::endl;
    std::cout << "Top: " << myStack.top() << std::endl;
    std::cout << "Size: " << myStack.size() << std::endl;
    std::cout << "Empty? (1 if yes, 0 if no): " << myStack.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "\033[32m______ COPY CONSTRUCTOR (MUTANTSTACK)_______\033[0m" << std::endl;
    MutantStack<int> myStack2(myStack);
    std::cout << "Address myStack: " << &myStack << std::endl;
    std::cout << "Address myStack2: " << &myStack2 << std::endl;
    std::cout << "MyStack 2:" << std::endl;
    for (MutantStack<int>::iterator it = myStack2.begin(); it != myStack2.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "\033[32m______ COPY ASSIGNMENT OPERATOR (MUTANTSTACK)_______\033[0m" << std::endl;
    MutantStack<int> myStack3 = myStack2;
    std::cout << "Address myStack2: " << &myStack2 << std::endl;
    std::cout << "Address myStack3: " << &myStack3 << std::endl;
    std::cout << "MyStack 3:" << std::endl;
    for (MutantStack<int>::iterator it = myStack3.begin(); it != myStack3.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "\033[32m_______ POP (MUTANTSTACK) _______\033[0m" << std::endl;
    std::cout << "    Pop..." << std::endl;
    myStack.pop();
    std::cout << "New top: " << myStack.top() << std::endl;
    std::cout << "New Size: " << myStack.size() << std::endl;
    std::cout << "Empty? (1 if yes, 0 if no): " << myStack.empty() << std::endl;
    std::cout << "    Popping rest of mutantStack items..." << std::endl;
    while (!myStack.empty())
        myStack.pop();
    std::cout << "New Size: " << myStack.size() << std::endl;
    std::cout << "Empty? (1 if yes, 0 if no): " << myStack.empty() << std::endl;
    std::cout << "    Ensuring that iteration on empty stack does not cause error..." << std::endl;
    std::cout << "My Mutant Stack: [ ";
    for (MutantStack<int>::iterator it = myStack.begin(); it != myStack.end(); it++)
        std::cout << *it;
    std::cout << "]" << std::endl;

    std::cout << "\033[34m----------------------------\033[0m" << std::endl;
    std::cout << "\033[34m-------- LIST TESTS --------\033[0m" << std::endl;
    std::cout << "\033[34m----------------------------\033[0m" << std::endl;
    std::list<int> myList;
    std::cout << "    Pushing [1, 2, 3, 4, 5]... " << std::endl;
    std::cout << std::endl;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    std::cout << "\033[32m_______ ITERATORS (LIST) ________\033[0m" << std::endl;
    std::cout << "My List: " << std::endl;
    for (std::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "List reverse iteration: " << std::endl;
    for (std::list<int>::reverse_iterator rit = myList.rbegin(); rit != myList.rend(); rit++)
        std::cout << *rit << " ";
    std::cout << std::endl;
    std::cout << "List const iterator (forward): " << std::endl;
    for (std::list<int>::const_iterator cit = myList.begin(); cit != myList.end(); cit++)
        std::cout << *cit << " ";
    std::cout << std::endl;
    std::cout << "List const iterator (reverse): " << std::endl;
    for (std::list<int>::const_reverse_iterator crit = myList.rbegin(); crit != myList.rend(); crit++)
        std::cout << *crit << " ";
    // std::cout << "    Modify with const iterator (won't compile)..." << std::endl;
    // for (std::list<int>::const_reverse_iterator crit = myList.rbegin(); crit != myList.rend(); crit++)
    // {
    //     std::cout << *crit << " ";
    //     (*crit) = 42;
    // }
    std::cout << std::endl;
    std::cout << "Front: " << myList.front() << std::endl;
    std::cout << "Back: " << myList.back() << std::endl;
    std::cout << "Size: " << myList.size() << std::endl;
    std::cout << "Empty? (1 if yes, 0 if no): " << myList.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "\033[32m______ COPY CONSTRUCTOR (LIST)_______\033[0m" << std::endl;
    std::list<int> list2(myList);
    std::cout << "Address myList: " << &myList << std::endl;
    std::cout << "Address list2: " << &list2 << std::endl;
    std::cout << "List 2:" << std::endl;
    for (std::list<int>::iterator it = list2.begin(); it != list2.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "\033[32m______ COPY ASSIGNMENT OPERATOR (LIST)_______\033[0m" << std::endl;
    std::list<int> list3 = list2;
    std::cout << "Address list2: " << &list2 << std::endl;
    std::cout << "Address list3: " << &list3 << std::endl;
    std::cout << "List 3:" << std::endl;
    for (std::list<int>::iterator it = list3.begin(); it != list3.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "\033[32m________ POP (LIST) ________\033[0m" << std::endl;
    std::cout << "    Pop..." << std::endl;
    myList.pop_back();
    std::cout << "New back: " << myList.back() << std::endl;
    std::cout << "New Size: " << myList.size() << std::endl;
    std::cout << "Empty? (1 if yes, 0 if no): " << myList.empty() << std::endl;
    std::cout << "    Popping rest of myList items..." << std::endl;
    while (!myList.empty())
        myList.pop_back();
    std::cout << "New Size: " << myList.size() << std::endl;
    std::cout << "Empty? (1 if yes, 0 if no): " << myList.empty() << std::endl;
    std::cout << "    Ensuring that iteration on empty list does not cause error..." << std::endl;
    std::cout << "My List: [ ";
    for (std::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it;
    std::cout << "]" << std::endl;
    std::cout << std::endl;
    std::cout << "\033[34m------------------------------\033[0m" << std::endl;
    std::cout << "\033[34m-------- FROM SUBJECT --------\033[0m" << std::endl;
    std::cout << "\033[34m------------------------------\033[0m" << std::endl;
    MutantStack<int> mstack;
    std::cout << "    Pushing [5, 17]...." << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "    Popping..." << std::endl;
    mstack.pop();
    std::cout << "New size: " << mstack.size() << std::endl;
    std::cout << "    Pushing [3, 5, 737, 0]..." << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "mstack Contents: " << std::endl;
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    std::stack<int> s(mstack);
    return 0;
}
