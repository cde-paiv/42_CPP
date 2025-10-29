/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:20:12 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/09/10 16:50:23 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie;
    std::string Zombiename;

    std::cout << "what's Zombie name: ";
    std::getline(std::cin, Zombiename);

    zombie = newZombie(Zombiename);
    if (!zombie)
    {
        std::cout << "Memory allocation failed" << std::endl;
        return (1);
    }
    zombie->announce();
    delete zombie;

    randomChump(Zombiename);

    return (0);
}