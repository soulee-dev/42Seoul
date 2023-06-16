/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:22:43 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 15:28:10 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
: AForm("No Name", false, 145, 137)
{
	std::cout << "[ShrubberyCreationForm] Default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, bool isSigned)
: AForm(name, isSigned, 145, 137)
{
	std::cout << "[ShrubberyCreationForm] Parameterized constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref)
: AForm(ref.name, ref.isSigned, 145, 137)
{
	*this = ref;
	std::cout << "[ShruberryCreationForm] Copy constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] Destructor" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	if (this != &ref)
		this->isSigned = ref.getIsSigned();
	return (*this);
}

void					ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw ShrubberyCreationForm::GradeTooLowException();
	if (this->getIsSigned())
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	else
		std::cout << executor.getName() << " couldn't sign " << this->getName() << " because form isn't signed" << std::endl;
}