/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:31:14 by soulee            #+#    #+#             */
/*   Updated: 2023/06/26 14:34:06 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	v;

	for (std::size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	try
	{
		std::cout << *(easyfind(v, 2)) << " is " << std::distance(v.begin(), easyfind(v, 2)) << "th value" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << *(easyfind(v, 100)) << " is " << std::distance(v.begin(), easyfind(v, 100)) << "th value" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}