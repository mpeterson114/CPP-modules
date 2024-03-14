#include "ScavTrap.hpp"

int main(void) 
{
    std::cout << "----------Constructors------------" << std::endl;
    std::cout << std::endl;
    ScavTrap c("A");
    ScavTrap d("B");
    std::cout << std::endl;

    std::cout << "-------------Battle---------------" << std::endl;
    std::cout << std::endl;
    c.attack("B");
    d.takeDamage(0);
    d.beRepaired(1);
    d.attack("A");
    c.attack("B");
    d.takeDamage(5);
    c.attack("B");
    d.takeDamage(5);
    d.beRepaired(1);
    d.beRepaired(1);
    c.attack("B");
    d.takeDamage(0);
    std::cout << std::endl;
    std::cout << "----------Destructors------------" << std::endl;
    std::cout << std::endl;
}