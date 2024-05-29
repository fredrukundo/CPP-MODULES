/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 05:13:52 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/29 01:42:33 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N 5

int main( void )
{
    Zombie* zomby = zombieHorde(N, "zombyy");
    for (int i = 0; i < N; i++)
    {
        zomby[i].announce();
    }
    delete [] zomby;
    return (0);
}