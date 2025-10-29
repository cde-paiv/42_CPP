/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:02:55 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/09/24 19:28:53 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _Weapon(weapon) {}

HumanA::~HumanA()
{
}

void HumanA::attack() {
    std::cout << _name << " attacks with their " << _Weapon.getType() << std::endl;
}
