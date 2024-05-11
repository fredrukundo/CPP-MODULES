/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 07:11:15 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/11 00:29:45 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <string>
#include <limits>
#include <sstream>
#include "Contact.hpp"

class PhoneBook {

private:
	int		index;
	Contact	contacts[8];
	void	display();

public:
	PhoneBook();

	void	addContact();
	void	searchContact();
};

void	puterr();
int		is_empty(Contact contact);
int		check_phone_number(std::string phoneNumber);
int		is_space(std::string str);
void	get_line(std::string &str, std::string name);

#endif