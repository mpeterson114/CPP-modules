#include "Zombie.hpp"

int main()
{
    std::cout << "NAME: HeapZombie" << std::endl; 
    Zombie *zombie = newZombie("HeapZombie");
    zombie->announce();
    delete(zombie);
    std::cout << "NAME: ChumpZombie" << std::endl;
    randomChump("ChumpZombie");
    return (0);
}