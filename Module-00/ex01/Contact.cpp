/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 05:48:44 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/16 02:06:22 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
}

Contact::Contact(std::string first, std::string last, std::string nickname
			, std::string phone, std::string secret) : first_name(first)
			, last_name(last), nickname(nickname), phone_number(phone)
			, darkest_secret(secret) {}

std::string	Contact::getFirstName()
{
	return this->first_name;
}

std::string	Contact::getLastName()
{
	return this->last_name;
}

std::string	Contact::getNickname()
{
	return this->nickname;
}

std::string	Contact::getPhoneNumber()
{
	return this->phone_number;
}

std::string	Contact::getDarkestSecret()
{
	return this->darkest_secret;
}
