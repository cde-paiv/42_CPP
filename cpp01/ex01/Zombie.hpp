/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:15:01 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/09/10 19:36:35 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie
{
    public:
        Zombie();
        ~Zombie();
        
        void    announce() const;
        void    setname(const std::string& name);

    private:
        std::string _name;
};

Zombie* zombieHorde(int n, const std::string& name);

