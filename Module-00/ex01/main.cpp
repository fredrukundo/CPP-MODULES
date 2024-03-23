/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:17:08 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/23 09:42:59 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int     main(void) {
    PhoneBook ph_book;
    
    std::string str;
    ph_book.Menu();
    while (str.compare("EXIT")) {
        if (str.compare("ADD") == 0)
            ph_book.addContact();
        else if (str.compare("SEARCH") == 0) {
            ph_book.printContacts();
            ph_book.search();
        }
        std::cout << "enter a command :> " << std::flush;
        std::cin >> str;
    }
    return 0;
}
