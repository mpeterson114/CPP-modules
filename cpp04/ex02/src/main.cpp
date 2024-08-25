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
    // /*Will not compile, we can't instantiate objects of an abstract class*/
    // AAnimal *animal = new AAnimal();
    std::cout << " * Expect compilation error * " << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "\033[38;5;209m************************************************\033[0m" << std::endl;
    std::cout << "\033[38;5;209m*               Animal Array Test              *\033[0m" << std::endl;
    std::cout << "\033[38;5;209m************************************************\033[0m" << std::endl;
    int number = 4;
    AAnimal *animalArr[number];
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
    std::cout << "\033[38;5;161m<<<< Destructors >>>>>\033[0m" << std::endl;
    for (int i = 0; i < number; i++){
        delete (animalArr[i]);
        std::cout << std::endl;
    }
        
    std::cout << std::endl;
    std::cout << "\033[38;5;209m************************************************\033[0m" << std::endl;
    std::cout << "\033[38;5;209m*      Deep Copy Test w/ Copy Constructor      *\033[0m" << std::endl;
    std::cout << "\033[38;5;209m************************************************\033[0m" << std::endl;
    Dog *dogA = new Dog();
    dogA->getBrain().setIdea("\033[32mDogA: I'm hungry\033[0m", 0);
    std::cout << std::endl;
    Dog *dogB = new Dog(*dogA);
    dogB->getBrain().setIdea("\033[34mDogB: Me too, gimme some food\033[0m", 0);
    std::cout << std::endl;
    std::cout << dogA->getBrain().getIdea(0) << std::endl;
    std::cout << dogB->getBrain().getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "\033[38;5;161m<<<< Destructors >>>>>\033[0m" << std::endl;
    delete dogA;
    std::cout << std::endl;
    std::cout << "Checking that dogB's still there..." << std::endl;
    std::cout << dogB->getBrain().getIdea(0) << std::endl;
    delete dogB;

    std::cout << std::endl;
    std::cout << "\033[38;5;209m************************************************\033[0m" << std::endl;
    std::cout << "\033[38;5;209m*    Deep Copy Test w/ Assignment Operator     *\033[0m" << std::endl;
    std::cout << "\033[38;5;209m************************************************\033[0m" << std::endl;
    Dog *dogC = new Dog();
    dogC->getBrain().setIdea("\033[32mDogC: hey I'm a dog\033[0m", 0);
    std::cout << std::endl;
    Dog *dogD = new Dog();
    *dogD = *dogC;
    dogD->getBrain().setIdea("\033[34mDogD: heyyyy same here\033[0m", 0);
    std::cout << std::endl;
    std::cout << dogC->getBrain().getIdea(0) << std::endl;
    std::cout << dogD->getBrain().getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "\033[38;5;161m<<<< Destructors >>>>>\033[0m" << std::endl;
    delete dogC;
    std::cout << std::endl;
    std::cout << "Checking that dogD's still there..." << std::endl;
    std::cout << dogD->getBrain().getIdea(0) << std::endl;
    delete dogD;
    std::cout << std::endl;

    return 0;
}






    // std::cout << "\033[38;5;209m************************************************\033[0m" << std::endl;
    // std::cout << "\033[38;5;209m*             Create Dog & Cat Tests           *\033[0m" << std::endl;
    // std::cout << "\033[38;5;209m************************************************\033[0m" << std::endl;
    // Dog *dogA = new Dog();
    // std::cout << std::endl;
    // AAnimal *animal1 = new Dog();
    // std::cout << std::endl;
    // AAnimal *animal2 = new Cat();
    // std::cout << std::endl;

    // std::cout << "  DogA:";
    // dogA->makeSound();
    // std::cout << "  animal1:";
    // animal1->makeSound();
    // std::cout << "  animal2:";
    // animal2->makeSound();

    // std::cout << std::endl;
    // std::cout << "\033[38;5;161m<<<< Destructors >>>>>\033[0m" << std::endl;
    // delete dogA;
    // std::cout << std::endl;
    // delete animal1;
    // std::cout << std::endl;
    // delete animal2;

    // return 0;