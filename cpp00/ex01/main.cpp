/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:01:52 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/06/26 16:27:12 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string command;

	std::cout << "Welcome to MyPhonebook!" << std::endl;

	while (std::cin)
	{
		std::cout << "\nChoose a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\n Exiting due to input error or EOF.\n";
			break;
		}

		for (size_t i = 0; i < command.length(); ++i)
			command[i] = std::toupper(command[i]);

		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContacts();
		else if (command == "EXIT")
		{
			std::cout << " Goodbye!" << std::endl;
			break;
		}
		else
		{
			std::cout << " Invalid command. Please use: ADD, SEARCH or EXIT." << std::endl;
		}
	}

	return 0;
}
