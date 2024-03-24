/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:17:08 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/24 06:37:45 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // cin, cout, endl
#include <string> // string class
#include <cstdlib> // exit() && EXIT_* macros
#include <stdio.h> // clearerr()
#include "PhoneBook.hpp"

using std::cin;
using std::cout;
using std::endl;

static inline bool isInputValid(const std::string& input) {
    return input == "ADD" || input == "SEARCH" || input == "EXIT";
}

void printWelcome(void)
{
    cout << "*-------------------------------------------*\n"
            "|                                           |\n"
            "|          ADD - Add a new contact          |\n"
            "|          SEARCH - Display a contact       |\n"
            "|          EXIT - Exit PhoneBook            |\n"
            "|                                           |\n"
            "*-------------------------------------------*" << endl;
}

std::string getInput(void)
{
    std::string input;

    while (1)
    {
        cout << "Enter a Command :> ";
        getline(cin, input);
        if (cin.eof() == true)
        {
            cin.clear();
            clearerr(stdin);
        }
        if (!input.empty() && isInputValid(input))
            break;
        cin.clear();
        cout << "Please insert a valid input" << endl;
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
            cout << "EXIT" << endl;
            return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}
