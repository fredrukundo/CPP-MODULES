/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 02:08:32 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/17 02:50:10 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
Zombie::Zombie()
{
}

Zombie::Zombie( std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie: " << this->name << " has been destroyed" << std::endl;
}

void Zombie::announce( void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}