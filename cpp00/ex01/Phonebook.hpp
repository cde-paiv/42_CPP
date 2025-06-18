/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:01:24 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/06/18 17:32:40 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class Phonebook
{
private:
    Contact contacts[8];
    int totalContacts;

public:
    Phonebook();
    ~Phonebook();
    
    void    addContact();
    void    searchContacts() const;
};