/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:15:59 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/09/10 19:32:11 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, const std::string& name)
{
    if (n <= 0)
        return NULL;

    Zombie* horde = new Zombie[n];

    for (int i = 0; i < n; i++)
        horde[i].setname(name);
    return horde;
}