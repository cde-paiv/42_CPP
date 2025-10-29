/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:03:52 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/10/15 19:50:38 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int   Fixed::fracBits = 8;

Fixed::Fixed() : _raw(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _raw(other._raw) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_raw = other._raw;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int n) {
    std::cout << "Int constructor called" << std::endl;
    this->_raw = n << fracBits;
}

Fixed::Fixed(float f) {
    std::cout << "Float constructor called" << std::endl;
    this->_raw = static_cast<int>(roundf(f * (1 << fracBits)));
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}

void    Fixed::setRawBits(int const raw) {
    this->_raw = raw;
}

float   Fixed::toFloat() const {
    return static_cast<float>(this->_raw) / static_cast<float>(1 << fracBits);
}

int Fixed::toInt() const {
    return this->_raw >> fracBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx) {
    os << fx.toFloat();
    return os;
}