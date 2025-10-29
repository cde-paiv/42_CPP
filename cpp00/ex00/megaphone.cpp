/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:55:45 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/06/26 12:43:30 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    std::string input;

    if (ac > 1)
    {
        int i = 1;
        while (i < ac)
        {
            input = av[i];
            size_t j = 0;
            while (j < input.length())
            {
                std::cout << (char)std::toupper(input[j]);
                j++;
            }
            i++;
            j = 0;
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
}