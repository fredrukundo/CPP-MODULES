/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:17:08 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/29 02:20:05 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static inline bool isInputValid(const std::string& input) {
    return input == "ADD" || input == "SEARCH" || input == "EXIT";
}

void printWelcome(void)
{
    std::cout << "*-------------------------------------------*\n"
            "|                                           |\n"
            "|          ADD - Add a new contact          |\n"
            "|          SEARCH - Display a contact       |\n"
            "|          EXIT - Exit PhoneBook            |\n"
            "|                                           |\n"
            "*-------------------------------------------*" << std::endl;
}

std::string getInput(void)
{
    std::string input;

    while (1)
    {
        std::cout << "Enter a Command :> ";
        getline(std::cin, input);
        if (std::cin.eof() == true)
        {
            std::cin.clear();
            clearerr(stdin);
        }
        if (!input.empty() && isInputValid(input))
            break;
        std::cin.clear();
        std::cout << "Please insert a valid input" << std::endl;
    }
    return input;
}

int main(void)
{
    PhoneBook pb;
    std::string input;

    printWelcome();
    while (1)
    {
        input = getInput();
        if (input == "ADD")
            pb.addContact();
        else if (input == "SEARCH")
            pb.searchContact();
        else
        {
            std::cout << "EXIT" << std::endl;
            return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}
