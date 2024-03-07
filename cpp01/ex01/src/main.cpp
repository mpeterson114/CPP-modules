/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:44:47 by mpeterso          #+#    #+#             */
/*   Updated: 2024/03/07 09:44:48 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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