#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // std::cout << "**** Subject Test ****" << std::endl;
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // delete j;
    // delete i;

    // std::cout << std::endl;
    std::cout << "**** Animal Array Test ****" << std::endl;
    int number = 4;
    Animal *animalArr[number];
    for (int i = 0; i < number; i++)
    {
        if (i < number / 2)
            animalArr[i] = new Dog();
        else
            animalArr[i] = new Cat();
        std::cout << "\033[32m  Animal[" << i << "] = " << animalArr[i]->getType() << "\033[0m" << std::endl;
        animalArr[i]->makeSound();
    }
    std::cout << std::endl;
    for (int i = 0; i < number; i++)
        delete (animalArr[i]);
    
    std::cout << std::endl;
    std::cout << "**** Deep Copy Test ****" << std::endl;
    
    return 0;
}