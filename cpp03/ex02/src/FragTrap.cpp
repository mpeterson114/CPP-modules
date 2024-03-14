#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap constructor for " << this->_name << " called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &src)
{
    ClapTrap::operator=(src);
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor for " << this->_name << " called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (this->_energyPoints <= 0)
    {
        std::cout << "No energy points left, FragTrap unable to attack" << std::endl;
        return ;
    }
    if (this->_hitPoints <= 0)
    {
        std::cout << "No hit points left, FragTrap unable to attack" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
}

void FragTrap::highFivesGuys(void)
{
    if (this->_hitPoints <= 0)
        std::cout << "FragTrap " << this->_name << " is dead, unable to high-five anyone." << std::endl;
    else
        std::cout << "FragTrap " << this->_name << ": \"HIGH-FIVE GUYS\"" << std::endl;
}