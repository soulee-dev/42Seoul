/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:30:17 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 17:03:58 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->type = "";
	std::cout << "[WrongAnimal] default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "[WrongAnimal] " << this->type << " : constructor" << std::endl; 
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref)
{
	*this = ref;
	std::cout << "[WrongAnimal] " << this->type << " : copy constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] " << this->type << " : destructor" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& ref)
{
	if (this != &ref)
		this->type = ref.type;
	std::cout << "[WrongAnimal] "<< this->type << " : overloaded assignment operator" << std::endl;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "[WrongAnimal] " << this->type << " : make sound" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}