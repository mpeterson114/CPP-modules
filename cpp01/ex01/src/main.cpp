#include "Zombie.hpp"

// void leaks(void)
// {
//     system("leaks Moar_Brainz");
// }

int main()
{
    int i = 0;
    int N = 3;

    Zombie *zombie = zombieHorde(N, "zOmBiEeeee");
    while (i < N){
        zombie[i].announce();
        i++;
    }
    //atexit(leaks);
    delete [] zombie;
    return 0;
}