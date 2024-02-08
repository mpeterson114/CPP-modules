#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
};

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " was destroyed" << std::endl;
};

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}