#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon{
    private:
        std::string type;
    
    public:
        Weapon(std::string type);
        ~Weapon(void);

        const std::string &getType(void) const;
        void setType(const std::string &newType);
};

#endif