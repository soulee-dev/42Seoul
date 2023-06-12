/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:09:12 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 19:28:51 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	for (size_t i = 0; i < 100; i ++)
		this->setIdea("Brainzzz....", i);
	std::cout << "[Brain] default constructor" << std::endl;
}

Brain::Brain(const Brain& ref)
{
	*this = ref;
	std::cout << "[Brain] copy constructor" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "[Brain] destructor" << std::endl;
}

Brain&	Brain::operator=(const Brain &ref)
{
	if (this != &ref)
	{
		for (size_t i = 0; i < 100; i++)
			this->setIdea(ref.getIdea(i), i);
	}
	std::cout << "[Brain] overloaded assignment" << std::endl;
	return (*this);
}

std::string	Brain::getIdea(size_t n) const
{
	return (this->ideas[n]);
}

void	Brain::setIdea(std::string idea, size_t n)
{
	this->ideas[n] = idea;
}
