/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:51:06 by soulee            #+#    #+#             */
/*   Updated: 2023/06/15 15:55:10 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	a;
	Bureaucrat	b("Soul Lee",1);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	try
	{
		a.increaseGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "error occured: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}