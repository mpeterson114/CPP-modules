/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:44:47 by mpeterso          #+#    #+#             */
/*   Updated: 2024/04/02 12:52:36 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int i = 0;
    int N = 7;

    Zombie *zombie = zombieHorde(N, "zOmBiEeeee");
    while (i < N){
        zombie[i].announce();
        i++;
    }
    delete [] zombie;
    return 0;
}