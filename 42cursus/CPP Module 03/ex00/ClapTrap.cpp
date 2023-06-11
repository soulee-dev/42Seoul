/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:56:50 by soulee            #+#    #+#             */
/*   Updated: 2023/06/11 14:44:19 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): name("")
{	
}

ClapTrap::ClapTrap(std::string name) : name(name)
{
}

ClapTrap::ClapTrap(const ClapTrap& ref)
{
	*this = ref;
}

ClapTrap::~ClapTrap()
{
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &ref)
{
	if (this != &ref)
		this->name = ref.name;
}