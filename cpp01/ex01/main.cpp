/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:14:08 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/09/10 19:35:38 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string zombieName;
    int numberZombie = 0;
    bool    input = false;

    while (!input)
    {
        std::cout << "How many zombies do you want to create (1 to 250): ";
        std::cin >> numberZombie;
        if (numberZombie <= 0 || numberZombie > 250)
            std::cout << "Invalid quantity, Please enter a number between 1 end 250." << std::endl;
        else
            input = true;
    }

    std::cout << "Name your Zombie: ";
    std::cin >> zombieName;

    Zombie *horde = zombieHorde(numberZombie, zombieName);
    if (!horde)
        return (1);

    for (int i = 0; i < numberZombie; i++)
        horde[i].announce();

    delete[] horde;
    return (0);
}