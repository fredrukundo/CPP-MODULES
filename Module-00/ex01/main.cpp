/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:17:08 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/11 00:13:13 by frukundo         ###   ########.fr       */
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
			book.addContact();
		if (input == "SEARCH")
			book.searchContact();
		if (input == "EXIT")
			break ;
	}
	return (0);
}
