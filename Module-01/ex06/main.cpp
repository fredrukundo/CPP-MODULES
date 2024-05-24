/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 21:11:36 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/24 21:15:12 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl h;
    if (ac != 2)
    {
        std::cerr << "INVALID ARGUMENTS" << std::endl;
        return (1);
    }
    h.complain(std::string (av[1]));
    return (0);
}
