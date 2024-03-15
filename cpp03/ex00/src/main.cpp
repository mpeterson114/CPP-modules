#include "ClapTrap.hpp"

int main(void) 
{
    std::cout << "----------Constructors------------" << std::endl;
    std::cout << std::endl;
    ClapTrap a = ClapTrap("A");
    ClapTrap b = ClapTrap("B");
    std::cout << std::endl;

    std::cout << "-------------Battle---------------" << std::endl;
    std::cout << std::endl;
    a.attack("B");
    b.takeDamage(0);
    b.beRepaired(1);
    a.attack("B");
    b.takeDamage(5);
    a.attack("B");
    b.takeDamage(5);
    b.beRepaired(1);
    b.beRepaired(1);
    a.attack("B");
    b.takeDamage(0);
    std::cout << std::endl;
    std::cout << "----------Destructors------------" << std::endl;
    std::cout << std::endl;
    return (0);
}