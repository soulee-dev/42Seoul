/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:43:19 by soulee            #+#    #+#             */
/*   Updated: 2023/04/24 19:43:19 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "PhoneBook.hpp"

std::string	truncate_string(std::string s)
{
	if (s.length() > 10)
	{
		s[9] = '.';
		s[10] = 0;
	}
	return (s);
}

void	print_spaces(int length)
{
	if (length < 10)
	{
		for (int i = 0; i < (int)(10 - length); i++)
			std::cout << " ";
	}
}

int	main()
{
	int				index;
	std::string		cmd;
	PhoneBook		phonebook;

	while (1)
	{
		std::cin >> cmd;
		if (cmd == "ADD")
		{
			phonebook.AddContact();
		}
		else if (cmd == "SEARCH")
		{
			if (phonebook.index > 0)
			{
					std::cout << "|     index|first_name| last_name|  nickname|" << std::endl;
				for (int i = 0; i < phonebook.index; i++)
				{
					print_spaces(i / 10);
					std::cout << i;
					std::cout << " ";

					print_spaces(phonebook.GetContact(i).first_name.length());
					std::cout << phonebook.GetContact(i).first_name;
					std::cout << " ";

					print_spaces(phonebook.GetContact(i).last_name.length());
					std::cout << phonebook.GetContact(i).last_name;
					std::cout << " ";

					print_spaces(phonebook.GetContact(i).nickname.length());
					std::cout << phonebook.GetContact(i).nickname;
					std::cout << std::endl;
				}
				std::cout << std::endl;
				std::cout << "Input index: ";
				std::cin >> index;

				index = index % 8;
				std::cout << "|     index|first_name| last_name|  nickname|" << std::endl;
				print_spaces(index / 10);
				std::cout << index;
				std::cout << " ";

				print_spaces(phonebook.GetContact(index).first_name.length());
				std::cout << phonebook.GetContact(index).first_name;
				std::cout << " ";

				print_spaces(phonebook.GetContact(index).last_name.length());
				std::cout << phonebook.GetContact(index).last_name;
				std::cout << " ";

				print_spaces(phonebook.GetContact(index).nickname.length());
				std::cout << phonebook.GetContact(index).nickname;
				std::cout << std::endl;
			}
		}
		else if (cmd == "EXIT")
		{
			break ;
		}
	}
	return (0);
}
