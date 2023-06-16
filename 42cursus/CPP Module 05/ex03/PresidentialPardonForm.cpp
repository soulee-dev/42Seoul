/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:16:26 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 20:26:43 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
: Form("No Name", false, 25, 5)
{
	std::cout << "[PresidentialPardonForm] Default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name, bool isSigned)
: Form(name, isSigned, 25, 5)
{
	std::cout << "[PresidentialPardonForm] Parameterized constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref)
: Form(ref.getName(), ref.getIsSigned(), 25, 5)
{
	*this = ref;
	std::cout << "[PresidentialPardonForm] Copy constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] Destructor" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	if (this != &ref)
		return (*this);
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw PresidentialPardonForm::GradeTooLowException();
	if (this->getIsSigned())
		std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because form isn't signed" << std::endl;
}