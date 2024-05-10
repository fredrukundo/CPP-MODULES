/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:17:08 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/10 18:36:44 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void printWelcome(void)
{
    std::cout << "*-------------------------------------------*\n"
            "|                                           |\n"
            "|          ADD - Add a new contact          |\n"
            "|          SEARCH - Display a contact       |\n"
            "|          EXIT - Exit PhoneBook            |\n"
            "|                                           |\n"
            "*-------------------------------------------*" << std::endl;
			
}

int	main(void)
{
	PhoneBook 	book;
	std::string	input;
	printWelcome();
	while (420)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (getline(std::cin, input).eof())
			break ;
		if (input == "ADD")
			book.add();
		if (input == "SEARCH")
			book.search();
		if (input == "EXIT")
			break ;
	}
	return (0);
}
