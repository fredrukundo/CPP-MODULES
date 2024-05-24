/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:43:51 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/24 18:39:06 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fcntl.h>
#include <fstream>

void print_error(std::string str)
{
    std::cerr << "Failed to open " << str << "." << std::endl;
    exit(1);
}

void replace(char **av, std::string str)
{
    std::ofstream   outfile;
    int             pos;
    
    outfile.open(std::string (av[1]) + "_replace");
    if (!outfile.is_open())
        print_error(std::string (av[1]) + "_replace");
    for (int i = 0; i < (int)str.size(); i++)
    {
        pos = str.find(av[2], i);
        if ( pos != -1 && pos == i && !std::string (av[2]).empty() && !std::string (av[3]).empty())
        {
            outfile << av[3];
            i += std::string (av[2]).size() - 1;
        }
        else
            outfile << str[i];
    }
    outfile.close();
}

int main(int ac, char **av)
{
    char				c;
    std::string	str;
	 std::ifstream	infile;
	 if (ac != 4)
	 {
		std::cerr << "Invalid argument" << std::endl;
		return (1);
	 }
	 infile.open(av[1]);
	 if (infile.fail())
	 	print_error(std::string (av[1]));
	while (!infile.eof() && infile >> std::noskipws >> c)
		str += c;
	infile.close();
	replace(av, str);
	return (0);
}
