/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:43:07 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/10 18:20:34 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	check_phone_number(std::string phoneNumber)
{
	int	i = 0;

	if (phoneNumber[i] == '+')
		i++;
	if (!phoneNumber[i])
		return (0);
	while (isdigit(phoneNumber[i]))
		i++;
	if (phoneNumber[i])
		return (0);
	return (1);
}

void	puterr()
{
	std::cout << "ERROR!" << std::endl;
	exit(1);
}

int	check_empty(Contact contact)
{
	if (contact.getDarkestSecret() == "EMPTY" && contact.getFirstName() == "EMPTY"
		&& contact.getLastName() == "EMPTY" && contact.getNickname() == "EMPTY"
		&& contact.getPhoneNumber() == "EMPTY")
		return (1);
	return (0);
}

int	is_full_spaces(std::string str)
{
	for (size_t i = 0; i < str.length() ; i++)
	{
		if (!isspace(str[i]))
			return (0);
	}
	return (1);
}

void	get_line(std::string &str, std::string name)
{
	if (getline(std::cin, str).eof())
		puterr();
	while (str.empty() || is_full_spaces(str))
	{
		std::cout << "Contact cannot have any empty field." << std::endl << name;
		if (getline(std::cin, str).eof())
			puterr();
	}
}