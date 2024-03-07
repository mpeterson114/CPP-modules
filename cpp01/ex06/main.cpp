/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:25:42 by mpeterso          #+#    #+#             */
/*   Updated: 2024/03/07 15:44:09 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Invalid input. Try the following: " << argv[0] << " <'DEBUG', 'INFO', 'WARNING' or 'ERROR'>" << std::endl;
        return (1);
    }
    Harl harl;
    std::string prompt = argv[1];
    harl.complain(prompt);
    return (0);
}