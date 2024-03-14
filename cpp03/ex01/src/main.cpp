#include "ScavTrap.hpp"

int main(void) 
{
    std::cout << "----------Constructors------------" << std::endl;
    std::cout << std::endl;
    ScavTrap c("A-clone");
    ScavTrap d("B-clone");
    std::cout << std::endl;

    std::cout << "-------------Battle---------------" << std::endl;
    std::cout << std::endl;
    c.attack("B-clone");
    c.beRepaired(22);
    c.takeDamage(21);
    c.beRepaired(22);
    c.guardGate();
    d.attack("A-clone");
    d.takeDamage(101);
    d.guardGate();
    d.takeDamage(15);
    d.attack("A-clone");
    std::cout << std::endl;
    std::cout << "----------Destructors------------" << std::endl;
    std::cout << std::endl;
}