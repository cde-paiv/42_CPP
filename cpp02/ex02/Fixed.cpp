/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:11:31 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/10/15 21:02:53 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fracBits = 8;

Fixed::Fixed() : _raw(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _raw(other._raw) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_raw = other._raw;
    }
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
    this->_raw = static_cast<int>(roundf(f * static_cast<float>(1 << fracBits)));
}

float Fixed::toFloat() const {
    return static_cast<float>(this->_raw) / static_cast<float>(1 << fracBits);
}

int Fixed::toInt() const {
    return this->_raw >> fracBits;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}

void Fixed::setRawBits(int const raw) {
    this->_raw = raw;
}

bool Fixed::operator>(const Fixed& rhs) const  { return this->_raw >  rhs._raw; }
bool Fixed::operator<(const Fixed& rhs) const  { return this->_raw <  rhs._raw; }
bool Fixed::operator>=(const Fixed& rhs) const  { return this->_raw >=  rhs._raw; }
bool Fixed::operator<=(const Fixed& rhs) const  { return this->_raw <=  rhs._raw; }
bool Fixed::operator==(const Fixed& rhs) const  { return this->_raw ==  rhs._raw; }
bool Fixed::operator!=(const Fixed& rhs) const  { return this->_raw !=  rhs._raw; }

Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed out;
    out._raw = this->_raw + rhs._raw;
    return out;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed out;
    out._raw = this->_raw - rhs._raw;
    return out;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed out;
    long long prod = static_cast<long long>(this->_raw) * static_cast<long long>(rhs._raw);
    out._raw = static_cast<int>(prod >> fracBits);
    return out;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    Fixed out;
    if (rhs._raw == 0)
    {
        out._raw = 0;
        return out;
    }
    long long num = (static_cast<long long>(this->_raw) << fracBits);
    out._raw = static_cast<int>(num / rhs._raw);
    return out;
}

Fixed& Fixed::operator++() {
    ++this->_raw;
    return *this;
}

Fixed& Fixed::operator--() {
    --this->_raw;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b; 
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx) {
    os << fx.toFloat();
    return os;
}