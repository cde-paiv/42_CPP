/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:04:02 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/10/15 19:44:23 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed {
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        Fixed(int n);
        Fixed(float f);

        int getRawBits() const;
        void    setRawBits(int const raw);

        float   toFloat() const;
        int    toInt() const;

    private:
        int _raw;
        static const int    fracBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fx);