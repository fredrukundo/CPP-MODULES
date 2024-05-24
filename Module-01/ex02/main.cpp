/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 05:32:18 by frukundo          #+#    #+#             */
/*   Updated: 2024/05/17 06:04:54 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void )
{
   std::string var = "HI THIS IS BRAIN";
   std::string* stringPTR = &var;
   std::string &stringREF = var;
   
  std::cout << "memory address of the string variable: " << &var << std::endl;
  std::cout << "memory address held by stringPTR: " << stringPTR << std::endl;
  std::cout << "memory address held by stringREF: " << &stringREF << std::endl;

  
  std::cout << "value of the string variable: " << var << std::endl;
  std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
  std::cout << "value pointed to by stringREF: " << stringREF << std::endl;
}