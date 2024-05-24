/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 04:39:42 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/17 05:00:39 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
   	std::string name;
	public:
		Zombie();
		~Zombie();
		void setName( std::string name);
		void announce( void );
};
Zombie* zombieHorde( int N, std::string name);

#endif