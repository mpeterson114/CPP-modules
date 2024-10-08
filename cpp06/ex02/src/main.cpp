#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/* - Dynamic_cast is used to convert pointers or references 
    of base class objects to derived class objects
    
    - Only used with polymorphic types when we want
    to determine the actual type of an object at runtime. 
    Useful when there are multiple derived classes */

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        Base* obj = generate();
        if (!obj)
            continue ;
        std::cout << "Check object type with Pointer(*): ";
        identify(obj);
        std::cout << "Check object type with Reference(&): "; 
        identify(*obj);
        std::cout << std::endl;

        delete (obj);
    }
    std::cout << "Test 'Identify()' w/ NULL: ";
    identify(NULL);
    std::cout << "Test 'Identify()' with '0': ";
    identify(0);
    return 0;
}
