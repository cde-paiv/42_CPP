/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:02:09 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/09/24 19:30:49 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}
Weapon::Weapon(std::string type)
{
    this->_type = type;
}
void    Weapon::setType(std::string type)
{
    this->_type = type;
}
std::string const &Weapon::getType(void)
{
    return (this->_type);
}