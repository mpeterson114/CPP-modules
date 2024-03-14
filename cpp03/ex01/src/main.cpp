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
    c.beRepaired(22);
    c.takeDamage(21);
    c.beRepaired(22);
    c.guardGate();
    d.attack("A");
    d.takeDamage(101);
    d.guardGate();
    d.takeDamage(15);
    d.attack("A");
    std::cout << std::endl;
    std::cout << "----------Destructors------------" << std::endl;
    std::cout << std::endl;
}