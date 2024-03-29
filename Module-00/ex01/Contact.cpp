/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 05:48:44 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/29 02:16:57 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setFirstName(std::string str) {
    this->first_name = str;
}

void Contact::setLastName(std::string str) {
    this->last_name = str;
}

void Contact::setNickName(std::string str) {
    this->nickname = str;
}

void Contact::setPhoneNumber(std::string str) {
    this->phone_number = str;
}

void Contact::setDarkestSecret(std::string str) {
    this->darkest_secret = str;
}

const std::string& Contact::getFirstName(void) const {
    return this->first_name;
}

const std::string& Contact::getLastName(void) const {
    return this->last_name;
}

const std::string& Contact::getNickname(void) const {
    return this->nickname;
}

const std::string& Contact::getPhoneNumber(void) const {
    return this->phone_number;
}

const std::string& Contact::getDarkestSecret(void) const {
    return this->darkest_secret;
}
