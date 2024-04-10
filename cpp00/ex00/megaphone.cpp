/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:46:55 by mpeterso          #+#    #+#             */
/*   Updated: 2024/02/01 09:46:56 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


int main(int argc, char **argv)
{
    int i;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    std::string message;
    for (i = 1; i < argc; i++)
        message += argv[i];
    for (std::string::iterator it = message.begin(); it != message.end(); it++)
        *it = std::toupper(*it);
    std::cout << message << std::endl;
    return (0);
}
