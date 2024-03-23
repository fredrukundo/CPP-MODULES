/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:20:51 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/22 11:36:38 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
   if (ac == 1)
      std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
   else
   {
      for (int i = 1; av[i]; i++)
      {
         for (int j = 0; av[i][j]; j++)
            std::cout << (char) toupper(av[i][j]);
         if (i < ac -1)
            std::cout << ' ';
      }
   }
   std::cout << std::endl;
   return (EXIT_SUCCESS);
}
