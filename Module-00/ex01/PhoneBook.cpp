/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 07:11:11 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/10 18:19:23 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <string>
#include <limits>
#include <sstream>

PhoneBook::PhoneBook()
{
	this->index = 0;
}

std::string	truncate(std::string str)
{
	if(str.length() > 10)
		return str.substr(0, 9) + '.';
	return str;
}

void	PhoneBook::print()
{
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::right << std::setw(10) << i;
		std::cout << "|";
		std::cout << std::right << std::setw(10) << truncate(contacts[i].getFirstName());
		std::cout << "|";
		std::cout << std::right << std::setw(10) << truncate(contacts[i].getLastName());
		std::cout << "|";
		std::cout << std::right << std::setw(10) << truncate(contacts[i].getNickname());
		std::cout << "\0";
		std::cout << std::endl;
	}
}

void	PhoneBook::add()
{
	std::cout << "First Name: ";
	std::string	firstName;
	get_line(firstName, "First Name: ");

	std::cout << "Last Name: ";
	std::string	lastName;
	get_line(lastName, "Last Name: ");

	std::cout << "Nickname: ";
	std::string	nickname;
	get_line(nickname, "Nickname: ");

	std::cout << "Phone Number: ";
	std::string	phoneNumber;
	get_line(phoneNumber, "Phone Number: ");
	while (!check_phone_number(phoneNumber))
	{
		std::cout << "Not a valid phone number." << std::endl;
		std::cout << "Phone Number: ";
		get_line(phoneNumber, "Phone Number: ");
	}
	std::cout << "Darkest Secret: ";
	std::string	darkestSecret;
	get_line(darkestSecret, "Darkest Secret: ");

	if (this->index == 8)
		this->index = 0;
	this->contacts[this->index++] = Contact(firstName, lastName
											,nickname, phoneNumber
											, darkestSecret);
}

void	PhoneBook::search()
{
	std::string	index;
	int i;

	this->print();
	std::cout << "Enter the index of the entry to display: ";
	if (getline(std::cin, index).eof())
		puterr();
	std::stringstream o(index);
	if (!(o >> i) || i < 0 || i > 7)
	{
		std::cout << "Wrong index." << std::endl;
		return ;
	}
	if (check_empty(contacts[i]))
	{
		std::cout << "Index empty." << std::endl;
		return ;
	}
	std::cout << std::left << std::setw(14) << "First name";
	std::cout << ": " << contacts[i].getFirstName() << std::endl;
	std::cout << std::left << std::setw(14) << "Last name";
	std::cout << ": " << contacts[i].getLastName() << std::endl;
	std::cout << std::left << std::setw(14) << "Nickname";
	std::cout << ": " << contacts[i].getNickname() << std::endl;
	std::cout << std::left << std::setw(14) << "Phone number";
	std::cout << ": " << contacts[i].getPhoneNumber() <<  std::endl;
	std::cout << std::left << std::setw(14) << "Darkest secret";
	std::cout << ": " << contacts[i].getDarkestSecret() << std::endl;
}