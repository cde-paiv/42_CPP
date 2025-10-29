/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:03:09 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/09/24 19:29:07 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _Weapon(NULL) {}

HumanB::~HumanB()
{
}
void HumanB::attack() {
    if (_Weapon)
        std::cout << _name << " attack with their " << _Weapon->getType() << std::endl;
    else
        std::cout << _name << " attack with nothing " << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) { _Weapon = &weapon; }
