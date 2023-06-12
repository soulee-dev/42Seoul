/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:30:17 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 19:58:30 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	this->type = "";
	std::cout << "[Animal] default constructor" << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "[Animal] " << this->type << " : constructor" << std::endl; 
}

Animal::Animal(const Animal& ref)
{
	*this = ref;
	std::cout << "[Animal] " << this->type << " : copy constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "[Animal] " << this->type << " : destructor" << std::endl;
}

Animal&	Animal::operator=(const Animal& ref)
{
	if (this != &ref)
		this->type = ref.type;
	std::cout << "[Animal] "<< this->type << " : overloaded assignment operator" << std::endl;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->type);
}