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
    // std::cout << "**** Animal Array Test ****" << std::endl;
    // int number = 4;
    // Animal *animalArr[number];
    // for (int i = 0; i < number; i++)
    // {
    //     if (i < number / 2)
    //         animalArr[i] = new Dog(); 
    //     else
    //         animalArr[i] = new Cat();
    //     std::cout << "\033[32m  Animal[" << i << "] = " << animalArr[i]->getType() << "\033[0m" << std::endl;
    //     animalArr[i]->makeSound();
    // }
    // std::cout << std::endl;
    // for (int i = 0; i < number; i++)
    //     delete (animalArr[i]);
    
    std::cout << std::endl;
    std::cout << "**** Dog Deep Copy Test w/ Copy Constructor ****" << std::endl;
    Dog *dog1 = new Dog();
    const Brain *dogBrain;

    dogBrain = &dog1->getBrain();
    dogBrain->setIdea("I'm hungry", 0);

    Dog *dog2 = new Dog(*dog1);
    const Brain *dB2;
    dB2 = &dog2->getBrain();
    dB2->setIdea("Me too, gimme some food", 0);
    std::cout << dB2->getIdea(0) << std::endl;

    delete dog1;
    delete dog2;

    // std::cout << std::endl;
    // std::cout << "**** Dog Deep Copy Test w/ Assignment Operator ****" << std::endl;
    // Dog *dogA = new Dog();
    // Dog *dogB = new Dog();
    // Brain *NEXT;
    // NEXT = &dogA->getBrain();
    // NEXT->setIdea("heyyyy.....", 0);
    // *dogB = *dogA;
    // Brain *nextDogsBrain;
    // nextDogsBrain = &dogB->getBrain();
    // std::cout << nextDogsBrain->getIdea(0) << std::endl;

    // delete dogA;
    // delete dogB;
    
    return 0;
}