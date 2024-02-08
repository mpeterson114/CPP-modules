#include "Zombie.hpp"

int main()
{
    std::cout << "*heapZombie*" << std::endl; 
    Zombie *zombie = newZombie("*heapZombie*");
    zombie->announce();
    delete(zombie);
    std::cout << "chumpZombie" << std::endl;
    randomChump("chumpZombie");
    return (0);
}