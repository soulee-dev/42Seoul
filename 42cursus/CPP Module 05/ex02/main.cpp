/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:51:06 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 19:53:31 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	{
		Bureaucrat				a("Soul Lee", 146);
		Bureaucrat				b("Mastermind", 1);
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
			a.executeForm(contract);
		}
		catch (std::exception& e)
		{
			std::cout << "error occured: " << e.what() << std::endl;
		}
		b.executeForm(contract);
	}
	{
		Bureaucrat				a("Soul Lee", 73);
		Bureaucrat				b("Mastermind", 1);
		RobotomyRequestForm		contract("Real Estate constracts", false);

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
			a.executeForm(contract);
		}
		catch (std::exception& e)
		{
			std::cout << "error occured: " << e.what() << std::endl;
		}
		b.executeForm(contract);
	}
	{
		Bureaucrat					a("Soul Lee", 26);
		Bureaucrat					b("Mastermind", 1);
		PresidentialPardonForm		pardon("Real Estate constracts", false);

		try
		{
			pardon.beSigned(a);
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
			pardon.beSigned(a);
			a.executeForm(pardon);
		}
		catch (std::exception& e)
		{
			std::cout << "error occured: " << e.what() << std::endl;
		}
		b.executeForm(pardon);
	}
	return (0);
}