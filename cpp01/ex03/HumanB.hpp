/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:03:22 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/09/24 19:06:08 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
	public:
			HumanB(std::string  name);
			~HumanB();
			void	attack();
			void	setWeapon(Weapon &weapon);
			
	private:
			std::string		_name;
			Weapon 			*_Weapon;
};