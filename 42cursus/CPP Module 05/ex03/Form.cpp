/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:56:07 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 20:26:12 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("No Name"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
	std::cout << "[Form] Default constructor" << std::endl;
}

Form::Form(const std::string name, bool isSigned, const int gradeToSign, const int gradeToExecute)
: name(name), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "[Form] Parameterized constructor" << std::endl;
}

Form::Form(const Form& ref)
: name(ref.name), gradeToSign(ref.gradeToSign), gradeToExecute(ref.gradeToExecute)
{
	*this = ref;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "[Form] Copy consturctor" << std::endl;
}

Form::~Form()
{
	std::cout << "[Form] Destructor" << std::endl;
}

Form&	Form::operator=(const Form& ref)
{
	if (this != &ref)
		this->isSigned = ref.getIsSigned();
	return (*this);
}

const std::string	Form::getName(void) const
{
	return (this->name);
}

bool				Form::getIsSigned(void) const
{
	return (this->isSigned);
}

int					Form::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

int					Form::getGradeToExecute(void) const
{
	return (this->gradeToExecute);
}

void				Form::beSigned(const Bureaucrat& signer)
{
	if (signer.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	if (!this->getIsSigned())
	{
		this->isSigned = true;
		std::cout << signer.getName() << " signed " << this->getName() << std::endl;
	}
	else
		std::cout << signer.getName() << " couldn't sign " << this->getName() << " because form is already signed" << std::endl;
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

std::ostream&	operator<<(std::ostream& out, const Form& ref)
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