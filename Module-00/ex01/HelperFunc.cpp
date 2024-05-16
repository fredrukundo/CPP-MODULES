/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelperFunc.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 03:50:10 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/16 03:50:14 by frukundo         ###   ########.fr       */
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
	std::cerr << "ERROR!" << std::endl;
	exit(1);
}

int	is_empty(Contact contact)
{
	if (contact.getDarkestSecret() == "" && contact.getFirstName() == ""
		&& contact.getLastName() == "" && contact.getNickname() == ""
		&& contact.getPhoneNumber() == "")
		return (1);
	return (0);
}

int	is_space(std::string str)
{
	for (size_t i = 0; i < str.length() ; i++)
	{
		if (!isspace(str[i]))
			return (0);// if not whitespace
	}
	return (1);//if all are whitespace
}

void	get_line(std::string &str, std::string name)
{
	if (getline(std::cin, str).eof())
		puterr();
	while (str.empty() || is_space(str))
	{
		std::cout << "Contact cannot have any empty field." << std::endl << name;
		if (getline(std::cin, str).eof())
			puterr();
	}
}