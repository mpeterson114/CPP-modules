#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void)
{
    int num = rand() % 3;
    switch (num)
    {
        case 0:
            std::cout << "New A created" << std::endl;
            return new A;
        case 1:
            std::cout << "New B created" << std::endl;
            return new B;
        case 2:
            std::cout << "New C created" << std::endl;
            return new C;
        default:
            std::cout << "Generate() error!" << std::endl;
            return NULL; 
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Class Type Unknown" << std::endl;
}

/* Return type in case of error when using dynamic_cast with 
    references is 'std::bad_cast' exception because with references,
    NULL cannot be returned */
void identify(Base& p)
{
    try 
    {
        A& a = dynamic_cast<A&>(p);
        (void) a;
        std::cout << "A" << std::endl;
        return;   
    } 
    catch (...) {}
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void) b;
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void) c;
        std::cout << "C" << std::endl;
        return;
    }
    catch (...) {}

    std::cout << "Class Type Unknown" << std::endl;
}
