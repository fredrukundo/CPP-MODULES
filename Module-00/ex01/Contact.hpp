/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 05:49:29 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/23 06:50:30 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
private:
	std::string _fname;
	std::string _lname;
	std::string _nickname;
	std::string _phone_num;
	std::string _darkestSecret;
	int			_index;

	std::string formatLen(std::string str) const;
	std::string getInput(std::string str) const;

public:
	Contact();
	~Contact();
	void		view(int index) const;
	void		init(void);
	void		display(int index) const;
	void		setIndex(int i);
};

#endif