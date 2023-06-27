/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:58:37 by soulee            #+#    #+#             */
/*   Updated: 2023/06/27 22:30:05 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	RPN	rpn;

	try
	{
		rpn.run(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}