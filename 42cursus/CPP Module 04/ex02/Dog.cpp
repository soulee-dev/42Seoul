/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:32:50 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 16:57:45 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "";
	std::cout << "[Dog] default constructor" << std::endl;
}

Dog::Dog(std::string type)
{
	this->type = type;
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
}

Dog&	Dog::operator=(const Dog& ref)
{
	if (this != &ref)
		this->type = ref.type;
	std::cout << "[Dog] " << this->type << " : overloaded assignment operator" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{ 
	std::cout << "[Dog] " << this->type << " : bark! bark!" << std::endl;
}
