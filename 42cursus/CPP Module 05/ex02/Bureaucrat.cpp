/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:51:30 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 15:31:21 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat(void) : name(""), grade(1)
{
	std::cout << "[Bureaucrat] Default constructor" << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
	this->setGrade(grade);
	std::cout << "[Bureaucrat] Parameterized constructor" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& ref) : name(ref.name)
{
	*this = ref;
	std::cout << "[Bureaucrat] Copy constructor" << std::endl;
}

// Deconstructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucat] Deconstructor" << std::endl;
}

// Overloaded assignmnet operator
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& ref)
{
	if (this != &ref)
		this->setGrade(grade);
	return (*this);
}

const std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void	Bureaucrat::increaseGrade(void)
{
	this->setGrade(this->grade - 1);
}

void	Bureaucrat::decreaseGrade(void)
{
	this->setGrade(this->grade + 1);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

void		Bureaucrat::signForm(AForm& form)
{
	form.beSigned(*this);
}

void		Bureaucrat::executeForm(AForm const& form)
{
	form.execute(*this);
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& ref)
{
	out << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
	return (out);
}

