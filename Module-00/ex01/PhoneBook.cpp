/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 07:11:11 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/24 11:06:19 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
    this->count = 0;
    std::cout << \
		"Welcome to Crappy! Created an empty phonebook for up to 8 contacts" \
		<< std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "SEE YOU SOON!" << std::endl;
}

using std::cin;

std::string getFormattedField(const std::string& field)
{
	if (field.length() > 10)
		return field.substr(0,9) + ".";
	return field;
}

void display_contact_info(Contact contact)
{
	std::cout << std::endl;
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
	std::cout << std::endl;
}

void PhoneBook::addContact(void)
{
    Contact new_contact;
    std::string input = "";

    // Get first name
    std::cout << "First name: ";
    while (true) {
        getline(std::cin, input);
        if (input.empty() || input.find_first_not_of(" \t") == std::string::npos) {
            std::cout << "First name cannot be empty or contain only spaces or tabs. Please enter again:";
            continue;
        }
        new_contact.setFirstName(input);
        break;
    }

    // Get last name
    std::cout << "Last name: ";
    while (true) {
        getline(std::cin, input);
        if (input.empty() || input.find_first_not_of(" \t") == std::string::npos) {
			cin.clear();
            std::cout << "Last name cannot be empty or contain only spaces or tabs. Please enter again: ";
            continue;
        }
        new_contact.setLastName(input);
        break;
    }

    // Get nickname
    std::cout << "Nickname: ";
    while (true) {
        getline(std::cin, input);
        if (input.empty() || input.find_first_not_of(" \t") == std::string::npos) {
			cin.clear();
            std::cout << "Nickname cannot be empty or contain only spaces or tabs. Please enter again: ";
            continue;
        }
        new_contact.setNickName(input);
        break;
    }

    // Get phone number
  	while (1)
	{
		std::cout << "Phone number 📞: ";
		getline(cin, input);
		if (!input.empty() && input.find_first_not_of("0123456789") != std::string::npos) 
		{
			cin.clear();
			std::cout << "Phone number must be fully composed by numbers" << std::endl;
			continue;
		}
		new_contact.setPhoneNumber(input);
		break;
	}

    // Get darkest secret
    std::cout << "Darkest secret 🕵️‍♂️ (yes, we promise not to tell anyone 🤭): ";
    while (true) {
        getline(std::cin, input);
        if (input.empty() || input.find_first_not_of(" \t") == std::string::npos) {
            std::cout << "Darkest secret cannot be empty or contain only spaces or tabs. Please enter again: ";
            continue;
        }
        new_contact.setDarkestSecret(input);
        break;
    }

    if (count > MAX_CONTACT_INDEX)
        this->contacts[count % 8] = new_contact;
    else
    {
        this->contacts[count % 8] = new_contact;
        this->count += 1;
    }
    std::cout << "Contact added successfully ✅" << std::endl;
}


void PhoneBook::searchContact(void)
{
	if (count == 0)
	{
		std::cout << "There are no contacts to display! ❌" << std::endl;
		return ;
	}
	std::cout << "\n|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (size_t i = 0; i < this->count; i += 1)
	{
		std::cout << "|" << std::right << std::setw(10) << i << "|";
		std::cout << std::right << std::setw(10) << getFormattedField(contacts[i].getFirstName()) << "|" ;
		std::cout << std::right << std::setw(10) << getFormattedField(contacts[i].getLastName()) << "|";
		std::cout << std::right << std::setw(10) << getFormattedField(contacts[i].getNickname()) << "|";
		std::cout << std::endl;
	}

	std::string index;
	int conv_index;

	while (1)
	{
		std::cout << "Please insert the index of the contact you'd like to display: ";
		getline(cin, index);
		if (!index.empty() && index.find_first_not_of("0123456789") == std::string::npos)
		{
			conv_index = atoi(index.c_str());
			if (conv_index <= MAX_CONTACT_INDEX)
				break;
		}
		cin.clear();
		std::cout << "Invalid input" << std::endl;
	}
	if ((size_t)conv_index > (count - 1))
		std::cout << "There's no contact with that index 📘" << std::endl;
	else
		display_contact_info(this->contacts[conv_index]);
}