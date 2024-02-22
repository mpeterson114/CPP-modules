#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB(void) {}

void HumanB::attack(void) const 
{
    if (this->_weapon)
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " has no weapon, unable to attack." << std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
    if (newWeapon.getType().empty())
    {
        std::cerr << "Error: New weapon must have a type" << std::endl;
        return ;
    }
    this->_weapon = &newWeapon;
}