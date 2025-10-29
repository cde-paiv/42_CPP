/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:02:51 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/09/24 19:05:58 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
	public:
			HumanA(std::string name, Weapon &weapon);
			~HumanA();
			void	attack();
	private:
			std::string 	_name;
			Weapon 			&_Weapon;
};