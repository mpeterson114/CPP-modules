/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:44:25 by mpeterso          #+#    #+#             */
/*   Updated: 2024/04/02 16:09:01 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::cout << "NAME: HeapZombie" << std::endl;
    Zombie *zombie = newZombie("HeapZombie");
    zombie->announce();
    delete(zombie);
    std::cout << "NAME: StackZombie" << std::endl;
    randomChump("StackZombie");
    return (0);
}