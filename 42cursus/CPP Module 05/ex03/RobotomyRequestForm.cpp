/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:28:35 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 20:26:51 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
: Form("No Name", false, 72, 45)
{
	std::cout << "[RobotomyRequestForm] Default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name, bool isSigned)
: Form(name, isSigned, 72, 45)
{
	std::cout << "[RobotomyRequstForm] Parameterized constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref)
: Form(ref.getName(), ref.getIsSigned(), 72, 45)
{
	*this = ref;
	std::cout << "[RobotomyRequestForm] Copy constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] Destructor" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	if (this != &ref)
		return (*this);
	return (*this);
}

void					RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw RobotomyRequestForm::GradeTooLowException();
	if (this->getIsSigned())
	{
		std::cout << "drr... drr... drr..." << std::endl;
		std::srand(std::time(0));

		double random = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
		if (random)
			std::cout << this->getName() << " has been robotomized haha" << std::endl;
		else
			std::cout << this->getName() << " has been failed to robotomize" << std::endl;
	}
	else
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because form isn't signed" << std::endl;
}