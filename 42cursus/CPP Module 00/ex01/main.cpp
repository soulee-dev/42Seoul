/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:43:19 by soulee            #+#    #+#             */
/*   Updated: 2023/06/06 20:14:34 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "PhoneBook.hpp"

std::string	truncate_string(std::string s)
{
	if (s.length() > 10)
	{
		s.resize(9);
		s.push_back('.');
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
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(255, '\n');
			std::cout << "Wrong input" << std::endl;
			return (1);
		}
		if (cmd == "ADD")
		{
			phonebook.AddContact();
		}
		else if (cmd == "SEARCH")
		{
			if (phonebook.GetIndex() > 0)
			{
				std::cout << "|     index|first_name| last_name|  nickname|" << std::endl;
				for (int i = 0; i < phonebook.GetIndex(); i++)
				{
					print_spaces(i / 10);
					std::cout << i;
					std::cout << " ";

					print_spaces(truncate_string(phonebook.GetContact(i).GetFirstname()).length());
					std::cout << truncate_string(phonebook.GetContact(i).GetFirstname());
					std::cout << " ";

					print_spaces(truncate_string(phonebook.GetContact(i).GetLastname()).length());
					std::cout << truncate_string(phonebook.GetContact(i).GetLastname());
					std::cout << " ";

					print_spaces(truncate_string(phonebook.GetContact(i).GetNickname()).length());
					std::cout << truncate_string(phonebook.GetContact(i).GetNickname());
					std::cout << std::endl;
				}
				std::cout << std::endl;
				std::cout << "Input index: ";
				std::cin >> index;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(255, '\n');
					std::cout << "Wrong input" << std::endl;
					return (1);
				}
				if (index >= 0 && index < phonebook.GetIndex())
				{
					index = index % 8;
					std::cout << "|     index|first_name| last_name|  nickname|" << std::endl;
					print_spaces(index / 10);
					std::cout << index;
					std::cout << " ";

					print_spaces(truncate_string(phonebook.GetContact(index).GetFirstname()).length());
					std::cout << truncate_string(phonebook.GetContact(index).GetFirstname());
					std::cout << " ";

					print_spaces(truncate_string(phonebook.GetContact(index).GetLastname()).length());
					std::cout << truncate_string(phonebook.GetContact(index).GetLastname());
					std::cout << " ";

					print_spaces(truncate_string(phonebook.GetContact(index).GetNickname()).length());
					std::cout << truncate_string(phonebook.GetContact(index).GetNickname());
					std::cout << std::endl;
				}
				else
					std::cerr << "Out Of Index" << std::endl;
			}
		}
		else if (cmd == "EXIT")
			return (0);
	}
	return (0);
}
