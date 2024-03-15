#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy)
{
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hitPoints = copy._hitPoints;
        this->_energyPoints = copy._energyPoints;
        this->_attackDamage = copy._attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->_energyPoints <= 0)
    {
        std::cout << "No energy points left, ClapTrap unable to attack" << std::endl;
        return ;
    }
    if (this->_hitPoints <= 0)
    {
        std::cout << "No hit points left, ClapTrap unable to attack" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if ((int)amount < 0)
    {
        std::cout << "'Amount' error, please enter a positive value" << std::endl;
        return ;
    }
    if (this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " is already dead, cannot be attacked." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " has been hit and has lost " << amount << " hit points." << std::endl;
    this->_hitPoints -= amount;
    if (this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " has died, ran out of hit points." << std::endl;
        if (this->_hitPoints < 0)
            this->_hitPoints = 0;
    }   
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if ((int)amount < 0)
    {
        std::cout << "'Amount' error, please enter a positive value" << std::endl;
        return ;
    }
    if (this->_energyPoints <= 0)
    {
        std::cout << "No energy points left, ClapTrap unable to repair itself" << std::endl;
        return ;
    }
    if (this->_hitPoints > 0)
        std::cout << "ClapTrap " << this->_name << " has repaired itself and gained " << amount << " hit points back." << std::endl;
    else
        std::cout << "ClapTrap " << this->_name << " has been revived! Gained " << amount << " hit points back." << std::endl;
    this->_energyPoints -= 1;
    this->_hitPoints += amount;
}
