/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:50:38 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 13:06:13 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->name = "default";
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	std::cout << "[ScavTrap] default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	std::cout << "[ScavTrap] " << this->name << " constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ref)
{
	*this = ref;
	std::cout << "[ScavTrap] " << this->name << " copy constructor" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] " << this->name << " destructor" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &ref)
{
	if (this != &ref)
	{
		this->name = ref.name;
		this->hit_point = ref.hit_point;
		this->energy_point = ref.energy_point;
		this->attack_damage = ref.attack_damage;
		std::cout << "[ScavTrap] overloaded assignment operator" << std::endl; 
	}
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->energy_point > 0 && this->hit_point > 0)
	{
		std::cout << "[ScavTrap] " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage" << std::endl;
		this->energy_point--;
	}
	else
		std::cout << "[ScavTrap] " << this->name << " has no energy or no hp" << std::endl; 
}

void	ScavTrap::guardGate(void)
{
	std::cout << "[ScavTrap] " << this->name << " is in gate guard mode" << std::endl;
}


