/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:51:06 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 14:54:41 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat				a("Soul Lee",2);
	ShrubberyCreationForm	contract("Real Estate constracts", false);


	try
	{
		contract.beSigned(a);
	}
	catch (std::exception& e)
	{
		std::cout << "error occured: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		a.increaseGrade();
		contract.beSigned(a);
		a.signForm(contract);
	}
	catch (std::exception& e)
	{
		std::cout << "error occured: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}