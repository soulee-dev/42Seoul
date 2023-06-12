/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:32:17 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 17:03:02 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "";
	std::cout << "[WrongCat] default constructor" << std::endl;
}

WrongCat::WrongCat(std::string type)
{
	this->type = type;
	std::cout << "[WrongCat] " << this->type << " : constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& ref)
{
	*this = ref;
	std::cout << "[WrongCat] " << this->type << " : copy constructor" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] " << this->type << " : destructor" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& ref)
{
	if (this != &ref)
		this->type = ref.type;
	std::cout << "[WrongCat] " << this->type << " : overloaded assignment operator" << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{ 
	std::cout << "[WrongCat] " << this->type << " : meow.. meow.." << std::endl;
}
