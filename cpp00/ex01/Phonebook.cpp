/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:01:17 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/06/18 18:46:48 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() : totalContacts(0) {}

Phonebook::~Phonebook() {}

static std::string formatfild(const std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Phonebook::addContact()
{
    std::string first, last, nick, number, secret;

    std::cout << "Enter first name: ";
    std::getline(std::cin, first);

    std::cout << "Enter last name: ";
    std::getline(std::cin, last);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, nick);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, number);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, secret);

    if (first.empty() || last.empty() || nick.empty() || number.empty() || secret.empty())
    {
        std::cout << "All fields are required. Contact not added.\n";
        return;
    }
    
    int index = totalContacts % 8;

    contacts[index].setFirstName(first);
    contacts[index].setLastName(last);
    contacts[index].setNickName(nick);
    contacts[index].setPhoneNumber(number);
    contacts[index].setSecret(secret);
    
    totalContacts++;
    std::cout << "Contact saved successfully.\n";
}


