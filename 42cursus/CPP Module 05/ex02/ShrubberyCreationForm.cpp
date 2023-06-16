/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:22:43 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 14:52:02 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
: name("No Name"), isSigned(false), gradeToSign(145), gradeToExecute(137)
{
	std::cout << "[ShrubberyCreationForm] Default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, bool isSigned)
: name(name), isSigned(isSigned), gradeToSign(145), gradeToExecute(137)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw ShrubberyCreationForm::GradeTooHighException();
	else if (grade > 150 || gradeToExecute > 150)
		throw ShrubberyCreationForm::GradeTooLowException();
	std::cout << "[ShrubberyCreationForm] Parameterized constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref)
: name(ref.name), gradeToSign(145), gradeToExecute(137)
{
	*this = ref;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw ShrubberyCreationForm::GradeTooHighException();
	else if (grade > 150 || gradeToExecute > 150)
		throw ShrubberyCreationForm::GradeTooLowException();
	std::cout << "[ShruberryCreationForm] Copy constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] Destructor" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	if (this != &ref)
		this->isSigned = ref.getIsSigne();
	return (*this);
}

void					ShrubberyCreationForm::beSigned(const Bureaucrat& signer)
{
	if (singer.getGrade() > this->getGradeToSign())
		throw ShrubberyCreationForm::GradeTooLowException();
	if (!this->getIsSigned())
	{
		this->isSigned = true;
		std::cout << signer.getName() << " signed " << this->getName() << std::endl;
	}
	else
		std::cout << signer.getName() << " couldn't sign " << this->getName() << " because form is already signed" << std::endl;
}

void					ShrubberyCreationForm::execute(Bureaucrat const& executor)
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw ShrubberyCreationForm::GradeTooLowException();
	if (this->getIsSigned())
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	else
		std::cout << signer.getName() << " couldn't sign " << this->getName() << " because form isn't signed" << std::endl;
}