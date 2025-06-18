/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:00:55 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/06/18 17:22:59 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string secret;

    public:
        Contact();
        ~Contact();

    // getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getSecret() const;

    // setters
    void setFirstName(const std::string value);
    void setLastName(const std::string value);
    void setNickName(const std::string value);
    void setPhoneNumber(const std::string value);
    void setSecret(const std::string value);
};