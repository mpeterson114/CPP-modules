#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA 
{
    private:
        std::string name;
        Weapon &weapon;
    
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);

        void attack(void) const;
        Weapon &getWeapon(void) const;
};

#endif