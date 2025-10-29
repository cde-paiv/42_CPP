/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:01:17 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/06/26 14:52:36 by cde-paiv         ###   ########.fr       */
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

void Phonebook::searchContacts() const
{
	if (totalContacts == 0)
	{
		std::cout << "Empty phonebook\n";
		return;
	}

	std::cout << "Index | First name | Last name  | Nickname\n";
	for (int i = 0; i < std::min(totalContacts, 8); ++i)
	{
		std::cout << "  " << i << "   | ";
		std::cout << std::setw(10) << formatfild(contacts[i].getFirstName()) << " | ";
		std::cout << std::setw(10) << formatfild(contacts[i].getLastName()) << " | ";
		std::cout << std::setw(10) << formatfild(contacts[i].getNickName()) << "\n";
	}

	std::cout << "Enter index of contact to view:\n";
	std::string input;
	std::getline(std::cin, input);

	if (input.size() != 1 || input[0] < '0' || input[0] > '7')
	{
		std::cout << "Invalid input.\n";
		return;
	}

	int index = input[0] - '0';
	if (index >= std::min(totalContacts, 8))
	{
		std::cout << "Invalid index.\n";
		return;
	}

	const Contact& c = contacts[index];
	std::cout << "First name:    " << c.getFirstName() << "\n";
	std::cout << "Last name:     " << c.getLastName() << "\n";
	std::cout << "Nickname:      " << c.getNickName() << "\n";
	std::cout << "Phone number:  " << c.getPhoneNumber() << "\n";
	std::cout << "Darkest secret:" << c.getSecret() << "\n";
}


