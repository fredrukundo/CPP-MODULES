/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:16:28 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/24 20:51:27 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void		Harl::debug(void)
{
	std::cout << MAGENTA << "[DEBUG]" << DEFAULT << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger.";
	std::cout << " I really do!" << std::endl;
	std::cout << std::endl;
}

void		Harl::info(void)
{
	std::cout << GRAY << "[INFO]" << DEFAULT <<std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << " You didn't put enough bacon in my burger! If you did,";
	std::cout << " I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}
void		Harl::warning(void)
{
	std::cout << YELLOW << "[WARNING]" << DEFAULT << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I've been coming for years whereas you started ";
	std::cout << "working here since last month." << std::endl;
	std::cout << std::endl;
}

void		Harl::error(void)
{
	std::cout << RED << "[ERROR]" << DEFAULT << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void		Harl::complain(std::string level)
{
	void	(Harl::*ptr_complain[4]) (void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};
	for (int i = 0; i < 4; i++)
	{
		if ( level == levels[i])
		{
			(this->*ptr_complain[i])();
			break;
		}
	}
}
