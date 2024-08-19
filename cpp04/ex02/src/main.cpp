#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << "\033[38;5;209m************************************************\033[0m" << std::endl;
    std::cout << "\033[38;5;209m*              Create AAnimal Test             *\033[0m" << std::endl;
    std::cout << "\033[38;5;209m************************************************\033[0m" << std::endl;
    std::cout << std::endl;
    // AAnimal *animal = new AAnimal();     // will return an error because we can't instantiate objects of an abstract class
    std::cout << " * Expect compilation error * " << std::endl;
    std::cout << std::endl;
    std::cout << "\033[38;5;209m************************************************\033[0m" << std::endl;
    std::cout << "\033[38;5;209m*             Create Dog & Cat Tests           *\033[0m" << std::endl;
    std::cout << "\033[38;5;209m************************************************\033[0m" << std::endl;
    Dog *dogA = new Dog();
    std::cout << std::endl;
    AAnimal *animal1 = new Dog();
    std::cout << std::endl;
    AAnimal *animal2 = new Cat();
    std::cout << std::endl;

    std::cout << "  DogA:";
    dogA->makeSound();
    std::cout << "  animal1:";
    animal1->makeSound();
    std::cout << "  animal2:";
    animal2->makeSound();

    std::cout << std::endl;
    std::cout << "\033[38;5;161m<<<< Destructors >>>>>\033[0m" << std::endl;
    delete dogA;
    std::cout << std::endl;
    delete animal1;
    std::cout << std::endl;
    delete animal2;

    return 0;
}