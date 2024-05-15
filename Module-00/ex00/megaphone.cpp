/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:20:51 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/16 00:33:26 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
   if (ac == 1)
   {
      std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
      return (0);
   }
   for (int i = 1; i < ac; i++)
   {
      std::string str = av[i];
      for (int j = 0; j < str.length(); j++)
         std::cout << (char)toupper(str[j]);
      if (i < ac - 1)
         std::cout << ' ';
   }
   std::cout << std::endl;
   return (EXIT_SUCCESS);
}
