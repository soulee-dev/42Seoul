/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:56:27 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 20:26:22 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "[Intern] Default constructor" << std::endl;
}

Intern::Intern(const Intern& ref)
{
	*this = ref;
	std::cout << "[Intern] Copy constructor" << std::endl;
}

Intern::~Intern()
{
	std::cout << "[Intern] Destructor" << std::endl;
}

Intern&	Intern::operator=(const Intern& ref)
{
	static_cast<void> (ref);
	return (*this);
}

static Form*	makeShrubberyCreationForm(const std::string name)
{
	return (new ShrubberyCreationForm(name, false));
}

static Form*	makeRobotomyRequestForm(const std::string name)
{
	return (new RobotomyRequestForm(name, false));
}

static Form*	makePresidentialPardonForm(const std::string name)
{
	return (new PresidentialPardonForm(name, false));
}

Form*	Intern::makeForm(const std::string type, const std::string name)
{
	Form*		(*forms[])(const std::string name) = {&makeShrubberyCreationForm, &makeRobotomyRequestForm, &makePresidentialPardonForm};
	std::string	types[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	for (int i = 0; i < 3; i++)
	{
		if (type == types[i])
			return (forms[i](name));
	}
	std::cout << "[Intern] There is no matching form" << std::endl;
	return (0);
}