/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:39:31 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/24 21:16:42 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void		Harl::debug(void)
{
	std::cout << MAGENTA << "[DEBUG]" << DEFAULT << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << " I really do!" << std::endl << std::endl;
}

void		Harl::info(void)
{
	std::cout << GRAY << "[INFO]" << DEFAULT <<std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << " You didn't put enough bacon in my burger! If you did,";
	std::cout << " I wouldn't be asking for more!" << std::endl << std::endl;
}
void		Harl::warning(void)
{
	std::cout << YELLOW << "[WARNING]" << DEFAULT << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << " I've been coming for years whereas you started ";
	std::cout << "working here since last month." << std::endl << std::endl;
}

void		Harl::error(void)
{
	std::cout << RED << "[ERROR]" << DEFAULT << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

int         Harl_levels(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
            return (i);
    }
    return (-1);
}

void	Harl::complain(std::string level)
{
	switch (Harl_levels(level))
	{
		case 0:
		{
			this->debug();
			this->info();
			this->warning();
			this->error();
			break ;
		}
		case 1:
		{
			this->info();
			this->warning();
			this->error();
			break ;
		}
		case 2:
		{
			this->warning();
			this->error();
			break ;
		}
		case 3:
		{
			this->error();
			break ;
		}
		default:
		{
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
		}
	}
}