/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:32:17 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 19:39:46 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "";
	this->brain = new Brain();
	for (size_t i = 0; i < 100; i++)
		this->brain->setIdea("Meow.. Meow..", i);
	std::cout << "[Cat] default constructor" << std::endl;
}

Cat::Cat(std::string type)
{
	this->type = type;
	std::cout << "[Cat] " << this->type << " : constructor" << std::endl;
}

Cat::Cat(const Cat& ref)
{
	*this = ref;
	std::cout << "[Cat] " << this->type << " : copy constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "[Cat] " << this->type << " : destructor" << std::endl;
	delete this->brain;
}

Cat&	Cat::operator=(const Cat& ref)
{
	if (this != &ref)
	{
		this->type = ref.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*(ref.getBrain()));
	}
	std::cout << "[Cat] " << this->type << " : overloaded assignment operator" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{ 
	std::cout << "[Cat] " << this->type << " : meow.. meow.." << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return (this->brain);
}

std::string	Cat::getIdea(size_t n) const
{
	return (this->brain->getIdea(n));
}

void	Cat::setIdea(std::string idea, size_t n)
{
	this->getBrain()->setIdea(idea, n);
}