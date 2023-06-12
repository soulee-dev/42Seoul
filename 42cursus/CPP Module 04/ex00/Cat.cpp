/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:32:17 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 16:48:03 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "";
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
}

Cat&	Cat::operator=(const Cat& ref)
{
	if (this != &ref)
		this->type = ref.type;
	std::cout << "[Cat] " << this->type << " : overloaded assignment operator" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{ 
	std::cout << "[Cat] " << this->type << " : meow.. meow.." << std::endl;
}
