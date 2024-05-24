/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 06:37:03 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/17 08:53:50 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

/*
	A reference to a Weapon object. This means HumanA does not own the weapon,
	but rather holds a reference to an existing Weapon object.
	This also implies that Weapon must be initialized when a HumanA object is created
*/
class HumanA
{
private:
	std::string	name;
	Weapon	&weapon;

public:
	void	attack();
	HumanA(std::string name, Weapon &weapon);
};
#endif