#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) 
{
    std::cout << "----------Constructors------------" << std::endl;
    std::cout << std::endl;
    std::string	fragTrapName = "A";
	std::string scavTrapName = "B";
	std::string clapTrapName = "C";

	FragTrap	fragTrap(fragTrapName);
	ScavTrap	scavTrap(scavTrapName);
	ClapTrap	clapTrap(clapTrapName);
    std::cout << std::endl;

    std::cout << "-------------Battle---------------" << std::endl;
    std::cout << std::endl;
    fragTrap.highFivesGuys();
	clapTrap.attack(scavTrapName);
	scavTrap.takeDamage(0);
	scavTrap.attack(fragTrapName);
	fragTrap.takeDamage(20);
	fragTrap.beRepaired(5);
    fragTrap.attack(scavTrapName);
    scavTrap.takeDamage(30);
	scavTrap.guardGate();
    scavTrap.beRepaired(20);
	fragTrap.highFivesGuys();
	fragTrap.takeDamage(5000);
	fragTrap.highFivesGuys();
    std::cout << std::endl;
    std::cout << "----------Destructors------------" << std::endl;
    std::cout << std::endl;
    return (0);
}

// std::string	fragTrapName = "FT-356";
// 	std::string scavTrapName = "SCVT-2000";
// 	std::string clapTrapName = "CT-42";

// 	FragTrap	fragTrap(fragTrapName);
// 	ScavTrap	scavTrap(scavTrapName);
// 	ClapTrap	clapTrap(clapTrapName);

// 	fragTrap.highFivesGuys();
// 	clapTrap.attack(scavTrapName);
// 	scavTrap.takeDamage(CLAPTRAP_DEFAULT_ATTACK_DAMAGE);
// 	scavTrap.attack(fragTrapName);
// 	fragTrap.takeDamage(SCAVTRAP_DEFAULT_ATTACK_DAMAGE);
// 	fragTrap.beRepaired(5);
// 	scavTrap.guardGate();
// 	for (int i = 0; i < 100; i++) {
// 		fragTrap.attack(scavTrapName);
// 		scavTrap.takeDamage(FRAGTRAP_DEFAULT_ATTACK_DAMAGE);
// 	}
// 	scavTrap.beRepaired(20);
// 	fragTrap.highFivesGuys();
// 	fragTrap.takeDamage(5000);
// 	fragTrap.highFivesGuys();
// 	return (0);