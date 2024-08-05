/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 04:46:14 by frukundo          #+#    #+#             */
/*   Updated: 2024/08/03 21:12:58 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{
     if (N <= 0) {
        std::cerr << "Error: N must be a positive integer." << std::endl;
        return nullptr;
    }
    Zombie* z = new Zombie[N];
    for (int i = 0; i < N; i++)
        z[i].setName(name);
    return (z);
}
