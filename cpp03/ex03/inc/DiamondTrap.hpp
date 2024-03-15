#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _name;

    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const &copy);
        DiamondTrap &operator=(DiamondTrap const &src);
        ~DiamondTrap();

        void    attack(const std::string &target);
        void    whoAmI(void);
};


#endif