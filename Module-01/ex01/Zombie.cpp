/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 04:55:04 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/28 03:00:29 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}
Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << this->name << " has been destroyed" << std::endl;
}
void Zombie::setName( std::string name)
{
    this->name = name;
}
void Zombie::announce( void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
