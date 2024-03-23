/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 05:48:44 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/23 10:28:41 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setIndex(int i) {
    this->_index = i;
}

std::string Contact::getInput(std::string str) const {
    std::string input = "";
    bool        valid = false;
    
    do
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            valid = true;
        else
        {
            std::cin.clear();
            std::cout << "Invalid input; please try again." << std::endl;
        }
    } while (!valid);
    return (input);
}

void    Contact::init(void) {
    std::cin.ignore();
    this->_fname = this->getInput("Enter your firstName: ");
    this->_lname = this->getInput("Enter your lastNmae: ");
    this->_nickname = this->getInput("Enter your NickName: ");
    this->_phone_num = this->getInput("Enter your PhoneNumber: ");
    this->_darkestSecret = this->getInput("Enter your darkest secret: ");
    
    std::cout << std::endl;
}

std::string Contact::formatLen(std::string str) const {
    if(str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Contact::view(int index) const {
    if (this->_fname.empty() || this->_lname.empty() || this->_nickname.empty())
        return;
    std::cout << "|" << std::setw(10) << index << std::flush;
    std::cout << "|" << std::setw(10) << this->formatLen(this->_fname) << std::flush;
    std::cout << "|" << std::setw(10) << this->formatLen(this->_lname) << std::flush;
    std::cout << "|" << std::setw(10) << this->formatLen(this->_nickname) << std::flush;
    std::cout << "|" << std::endl;
    
}

void Contact::display(int index) const {
    if (this->_fname.empty() || this->_lname.empty() || this->_nickname.empty())
        return;
    std::cout << std::endl;
    std::cout << "******** CONTACT ID:" << index << " ********" << std::endl;
    std::cout << "First Name:\t" << this->_fname << std::endl;
    std::cout << "Last Name:\t" << this->_lname << std::endl;
    std::cout << "Nickname:\t" << this->_nickname << std::endl;
    std::cout << std::endl;
}
