/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:24:29 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 20:29:00 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	checkLeaks()
{
	system("leaks intern");
}

int	main()
{
	Bureaucrat	a("Soul Lee", 1);
	Intern		someRandomIntern;
	Form*		rrf;

	atexit(checkLeaks);
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf->beSigned(a);
	rrf->execute(a);

	delete rrf;
}