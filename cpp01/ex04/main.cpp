/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:49:43 by cde-paiv          #+#    #+#             */
/*   Updated: 2025/10/10 11:39:04 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: " << av[0] << " <filename> <oldword> <newword>" << std::endl;
        return (1);
    }
    
    const std::string filename = av[1];
    const std::string s1 = av[2];
    const std::string s2 = av[3];
    const std::string outname = filename + ".replace";

    if (s1.empty())
    {
        std::cerr << "Error: <oldword> must be non-empty" << std::endl;
        return (1);
    }
    if (s1 == s2)
    {
        std::ifstream in(filename.c_str());
        if(!in.is_open())
        {
            std::cerr << "Error: can't open input file" << std::endl;
            return (1);
        }
        std::ofstream out(outname.c_str());
        if (!out.is_open())
        {
            std::cerr << "Error: can't create output file" << std::endl;
            return (1);
        }
        out << in.rdbuf();
        return (0);
    }

    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Error: can't create output file" << std::endl;
        return (1);
    }

    std::ofstream outfile(outname.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: create output file" << std::endl;
        return (1);
    }

    std::string line;
    while (std::getline(infile, line))
    {
        std::size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outfile << line;
        if (!infile.eof())
            outfile << '\n';
    }
    return (0);
}