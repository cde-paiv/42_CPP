/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:19:20 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/09/10 16:35:13 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <iomanip>
# include <string>

class Zombie

{
    public:
        Zombie(std::string name);
        ~Zombie();
        void    announce(void);
    private:
        std::string _name;
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);