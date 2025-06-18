/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:00:41 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/06/18 17:28:02 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setFirstName(const std::string value) {
    firstName = value;
}

void Contact::setLastName(const std::string value) {
    lastName = value;
}

void Contact::setNickName(const std::string value) {
    nickName = value;
}

void Contact::setPhoneNumber(const std::string value) {
    phoneNumber = value;
}

void Contact::setSecret(const std::string value) {
    secret = value;
}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickName() const {
    return nickName;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getSecret() const {
    return secret;
}