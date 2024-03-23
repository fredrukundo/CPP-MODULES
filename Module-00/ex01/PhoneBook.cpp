/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 07:11:11 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/23 10:29:24 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    //this->_index = 0;
	std::cout << \
		"Welcome to Crappy! Created an empty phonebook for up to 8 contacts" \
		<< std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "See you soon!" << std::endl;
}

void    PhoneBook::Menu(void) const {
    std::cout << std::endl;
    std::cout << "📞 Welcome to Your Awesome PhoneBook 📖" << std::endl;
    std::cout << std::endl;
    std::cout << "--------------USAGE---------------" << std::endl;
    std::cout << "ADD\t: To add a contact." << std::endl;
    std::cout << "SEARCH\t: To search for a contact." << std::endl;
    std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl;
}

void    PhoneBook::addContact(void) {
    static int  i;
    this->_contacts[i % 8].init();
    this->_contacts[i % 8].setIndex(i % 8);
    i++;
}

void    PhoneBook::printContacts(void) const {
    std::cout << "********* PHONBOOK CONTACTS *********" << std::endl;
    std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
    for (size_t i = 0; i < 8; i++) {
        this->_contacts[i].view(i);
    }
    std::cout << std::endl;
}

int     PhoneBook::_readInput() const {
    int     input = -1;
    bool    valid = false;
    do
    {
        std::cout << " enter the contact index: " << std::flush;
        std::cin >> input;
        if (std::cin.good() && (input >= 0 && input <= 8)) {
            valid = true;
        } else {
            
            std::cin.clear();
            
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Invalid index; please re-enter." << std::endl;
        }
    } while (!valid);
    return (input);
}

void    PhoneBook::search(void) const {
    int i = this->_readInput();
    this->_contacts[i].display(i);
}
