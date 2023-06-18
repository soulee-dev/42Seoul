/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:28:41 by soulee            #+#    #+#             */
/*   Updated: 2023/06/18 18:45:04 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(int argc, char *argv[])
{
	Data		prev;
	Data*		next;
	uintptr_t	ptr;

	if (argc != 2)
	{
		std::cerr << "Error: invalid argument" << std::endl;
		return (1);
	}
	prev.name = argv[1];
	std:: cout << "prev: " << prev.name << std::endl;

	ptr = Serializer::serialize(&prev);
	std::cout << "ptr : " << ptr << std::endl;

	next = Serializer::deserialize(ptr);
	std::cout << "next : " << next->name << std::endl;

	return (0);
}