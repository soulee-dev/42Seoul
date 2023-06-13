/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:32:50 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 22:01:27 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "";
	this->brain = new Brain();
	for (size_t i = 0; i < 100; i++)
		this->brain->setIdea("Bark! Bark!", i);
	std::cout << "[Dog] default constructor" << std::endl;
}

Dog::Dog(std::string type)
{
	this->type = type;
	this->brain = new Brain();
	for (size_t i = 0; i < 100; i++)
		this->brain->setIdea("Bark! Bark!", i);
	std::cout << "[Dog] " << this->type << " : constructor" << std::endl;
}

Dog::Dog(const Dog& ref)
{
	*this = ref;
	std::cout << "[Dog] " << this->type << " : copy constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "[Dog] " << this->type << " : destructor" << std::endl;
	delete this->brain;
}

Dog&	Dog::operator=(const Dog& ref)
{
	if (this != &ref)
	{
		this->type = ref.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*(ref.getBrain()));
	}
	std::cout << "[Dog] " << this->type << " : overloaded assignment operator" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{ 
	std::cout << "[Dog] " << this->type << " : bark! bark!" << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return (this->brain);
}

std::string	Dog::getIdea(size_t n) const
{
	return (this->brain->getIdea(n));
}

void	Dog::setIdea(std::string idea, size_t n)
{
	this->getBrain()->setIdea(idea, n);
}