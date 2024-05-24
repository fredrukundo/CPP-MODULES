/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 06:26:41 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/17 06:34:54 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type)
{
    this->type = type;
}
Weapon::~Weapon(){}

const std::string& Weapon::getType(void)
{
    return this->type;
}

void Weapon::setType( std::string type)
{
    this->type = type;
}