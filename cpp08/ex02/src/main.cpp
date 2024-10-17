#include "MutantStack.hpp"
#include <stack>

/* Stack: LIFO (last in first out)- most recently added element
    is the first to be removed 
    - Elements can only be accessed by pushing to or popping from 
    the top of the stack (no way to iterate through)
    
    -We can add iterator functionality to our custom MutantStack 
    class by accessing the underlying container structure (deque in
    the case of stack) through the protected 'c' member variable */

