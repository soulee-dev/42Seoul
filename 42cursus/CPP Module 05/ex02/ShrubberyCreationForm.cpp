/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:22:43 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 16:25:17 by soulee           ###   ########.fr       */
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
: AForm(ref.getName(), ref.getIsSigned(), 145, 137)
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
		return (*this);
	return (*this);
}

void					ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw ShrubberyCreationForm::GradeTooLowException();
	if (this->getIsSigned())
	{
		std::ofstream	outfile((this->getName() + "_shrubbery").c_str());
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		outfile << "       _-_" << std::endl;
		outfile << "    /~~   ~~\\" << std::endl;
		outfile << " /~~         ~~\\" << std::endl;
		outfile << "{               }" << std::endl;
		outfile << " \\  _-     -_  /" << std::endl;
		outfile << "   ~  \\\\ //  ~" << std::endl;
		outfile << "_- -   | | _- _" << std::endl;
		outfile << "  _ -  | |   -_" << std::endl;
		outfile << "      // \\\\" << std::endl;
		outfile.close();
	}
	else
		std::cout << executor.getName() << " couldn't sign " << this->getName() << " because form isn't signed" << std::endl;
}