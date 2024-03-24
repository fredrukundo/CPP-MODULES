/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 07:11:15 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/24 04:53:30 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8
#define MAX_CONTACT_INDEX 7

class PhoneBook
{
private:
    size_t count;
    Contact contacts[MAX_CONTACTS];

public:
    PhoneBook();
    ~PhoneBook();
    void addContact(void);
    void searchContact(void);
};

#endif