#include "Array.hpp"

/* Templates need to be visible to the compiler in every translation
 unit that uses them; compiler generates the code 
 based on the template arguments at compile-time 
 
 .tpp files are not compiled separately like .cpp files, instead
    they're included with the header file 
    
   Default initialization: 
      -Built-in types (int, float, char, etc.) : uninitialized (garbage values)
      -User-defined types (i.e., class with default constructor) :
         default constructor will be called for each element 
   */

