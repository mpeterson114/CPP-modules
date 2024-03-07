/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:44:25 by mpeterso          #+#    #+#             */
/*   Updated: 2024/03/07 09:44:26 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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