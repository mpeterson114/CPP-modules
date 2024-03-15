#include "ScavTrap.hpp"

int main(void) 
{
    std::cout << "----------Constructors------------" << std::endl;
    std::cout << std::endl;
    std::string	clapTrapName = "A";
	std::string scavTrapName = "B";

	ClapTrap	clapTrap(clapTrapName);
	ScavTrap	scavTrap(scavTrapName);
    std::cout << std::endl;

    std::cout << "-------------Battle---------------" << std::endl;
    std::cout << std::endl;
    scavTrap.guardGate();
    scavTrap.attack(clapTrapName);
    clapTrap.takeDamage(20);
    clapTrap.attack(scavTrapName);
    clapTrap.beRepaired(10);
    std::cout << std::endl;
    std::cout << "retaliation..." << std::endl;
    for (int i = 0; i < 9; i++)
    {
        clapTrap.attack(scavTrapName);
        scavTrap.takeDamage(0);
    }
    clapTrap.attack(scavTrapName);
    std::cout << std::endl;
    std::cout << "----------Destructors------------" << std::endl;
    std::cout << std::endl;
    return (0);
}