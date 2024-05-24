/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 06:41:28 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/17 08:48:04 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

/*
	A pointer to a Weapon object. This means HumanB can hold a reference to a weapon,
	 but it can also choose to have no weapon (i.e., weapon can be nullptr).
*/
class HumanB
{
private:
	std::string	name;
	Weapon	*weapon;

public:
	void	attack();
    void	setWeapon(Weapon &weapon);
	HumanB(std::string name);
};
#endif