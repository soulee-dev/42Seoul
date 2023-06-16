/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:56:07 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 14:38:55 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("No Name"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
	std::cout << "[AForm] Default constructor" << std::endl;
}

AForm::AForm(const std::string name, bool isSigned, const int gradeToSign, const int gradeToExecute)
: name(name), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "[AForm] Parameterized constructor" << std::endl;
}

AForm::AForm(const AForm& ref)
: name(ref.name), gradeToSign(ref.gradeToSign), gradeToExecute(ref.gradeToExecute)
{
	*this = ref;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "[AForm] Copy consturctor" << std::endl;
}

AForm::~AForm()
{
	std::cout << "[AForm] Destructor" << std::endl;
}

AForm&	AForm::operator=(const AForm& ref)
{
	if (this != &ref)
		this->isSigned = ref.getIsSigned();
	return (*this);
}

const std::string	AForm::getName(void) const
{
	return (this->name);
}

bool				AForm::getIsSigned(void) const
{
	return (this->isSigned);
}

int					AForm::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

int					AForm::getGradeToExecute(void) const
{
	return (this->gradeToExecute);
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

std::ostream&	operator<<(std::ostream& out, const AForm& ref)
{
	if (ref.getIsSigned())
	{
		out << ref.getName()
		<< " is signed, required grade for signing is " << ref.getGradeToSign()
		<< " and required grade for execute is " << ref.getGradeToExecute();
	}
	else
	{
		out << ref.getName()
		<< " is not signed, required grade for signing is " << ref.getGradeToSign()
		<< " and required grade for execute is " << ref.getGradeToExecute();
	}
	return (out);
}