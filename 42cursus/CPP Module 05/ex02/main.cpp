/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:51:06 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 16:04:48 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	// ShrubberyCreationForm
	Bureaucrat				a("Soul Lee", 146);
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