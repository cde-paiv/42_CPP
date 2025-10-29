/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:13:51 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/10/10 14:43:53 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Harl {
    public:
        Harl();
        ~Harl();

        void    complain(const std::string& level);

    private:
        void    debug() const;
        void    info() const;
        void    warning() const;
        void    error() const;
};