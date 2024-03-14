#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src)
{
    ClapTrap::operator=(src);
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap deconstructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->_energyPoints <= 0)
    {
        std::cout << "No energy points left, ScavTrap unable to attack" << std::endl;
        return ;
    }
    if (this->_hitPoints <= 0)
    {
        std::cout << "No hit points left, ScavTrap unable to attack" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
}

void ScavTrap::guardGate(void)
{
    if (this->_hitPoints <= 0)
        std::cout << "ScavTrap " << this->_name << " is dead, unable to enter Gatekeeper mode." << std::endl;
    else
        std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper mode." << std::endl;
}

