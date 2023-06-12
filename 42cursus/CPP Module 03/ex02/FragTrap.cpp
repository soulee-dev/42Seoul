/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:50:38 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 13:11:49 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->name = "default";
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
	std::cout << "[FragTrap] default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
	std::cout << "[FragTrap] " << this->name << " constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref)
{
	*this = ref;
	std::cout << "[FragTrap] " << this->name << " copy constructor" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] " << this->name << " destructor" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &ref)
{
	if (this != &ref)
	{
		this->name = ref.name;
		this->hit_point = ref.hit_point;
		this->energy_point = ref.energy_point;
		this->attack_damage = ref.attack_damage;
		std::cout << "[FragTrap] overloaded assignment operator" << std::endl; 
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "[FragTrap] " << this->name << " yay, highfives guys" << std::endl;
}


