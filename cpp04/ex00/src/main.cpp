/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:23:52 by mpeterso          #+#    #+#             */
/*   Updated: 2024/06/03 12:29:00 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "\033[38;5;161m >>> Sample tests from subject <<< \033[0m" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete(i);
    delete(j);
    delete(meta);
    std::cout << std::endl;
    
    std::cout << "\033[38;5;161m >>> More tests... <<< \033[0m" << std::endl;
    {
        std::cout << "\033[38;5;192mNew cat object from derived class 'Cat':\033[0m" << std::endl;
        const Cat *cat1 = new Cat();
        std::cout << "Type: " << cat1->getType() << std::endl;
        cat1->makeSound();
        delete(cat1);
    }
    std::cout << std::endl;
    {
        std::cout << "\033[38;5;192mNew cat object from base class 'Animal':\033[0m" << std::endl;
        const Animal *cat2 = new Cat();
        std::cout << "Type: " << cat2->getType() << std::endl;
        cat2->makeSound();
        delete(cat2);
    }
    std::cout << std::endl;
    {
        std::cout << "\033[38;5;192mNew dog object from derived class 'Dog':\033[0m" << std::endl;
        const Dog *dog1 = new Dog();
        std::cout << "Type: " << dog1->getType() << std::endl;
        dog1->makeSound();
        delete(dog1);
    }
    std::cout << std::endl;
    {
        std::cout << "\033[38;5;192mNew dog object from base class 'Animal':\033[0m" << std::endl;
        const Animal *dog2 = new Dog();
        std::cout << "Type: " << dog2->getType() << std::endl;
        dog2->makeSound();
        delete(dog2);
    }
    // Won't compile:
    // const Dog *dog3 = new Animal();
    // std::cout << "Type: " << dog3->getType() << std::endl;
    // dog3->makeSound();
    // delete(dog3);

    std::cout << std::endl;
    std::cout << "\033[38;5;161m >>> Wrong Animal/Cat tests... <<< \033[0m" << std::endl;
    {
        std::cout << "\033[38;5;192mNew WrongAnimal object from base class 'WrongAnimal':\033[0m" << std::endl;
        const WrongAnimal *wrongAnimal = new WrongAnimal();
        std::cout << "Type: " << wrongAnimal->getType() << std::endl;
        wrongAnimal->makeSound();
        delete(wrongAnimal);
    }
    std::cout << std::endl;
    {
        std::cout << "\033[38;5;192mNew WrongCat object from derived class 'WrongCat':\033[0m" << std::endl;
        const WrongAnimal *wrongCat1 = new WrongCat();
        std::cout << "Type: " << wrongCat1->getType() << std::endl;
        wrongCat1->makeSound();
        delete(wrongCat1);
    }
    std::cout << std::endl;
    {
        std::cout << "\033[38;5;192mNew WrongCat object from base class 'WrongAnimal':\033[0m" << std::endl;
        const WrongAnimal *wrongCat2 = new WrongCat();
        std::cout << "Type: " << wrongCat2->getType() << std::endl;
        wrongCat2->makeSound();
        delete(wrongCat2);
    }
    return 0;
}