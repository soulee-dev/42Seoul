/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:56:50 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 13:23:02 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->name = "default";
	this->hit_point = 10;
	this->energy_point = 10;
	this->attack_damage = 0;
	std::cout << "[ClapTrap] default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hit_point = 10;
	this->energy_point = 10;
	this->attack_damage = 0;
	std::cout << "[ClapTrap] " << this->name << " constructor" << std::endl;
}

// I should check this constructor before evaluating;
ClapTrap::ClapTrap(const ClapTrap& ref)
{
	*this = ref;
	std::cout << "[ClapTrap] " << this->name << " copy constructor" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] " << this->name << " destructor" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &ref)
{
	if (this != &ref)
	{
		this->name = ref.name;
		this->hit_point = ref.hit_point;
		this->energy_point = ref.energy_point;
		this->attack_damage = ref.attack_damage;
		std::cout << "[ClapTrap] overloaded assignment operator" << std::endl;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energy_point > 0 && this->hit_point > 0)
	{
		std::cout << "[ClapTrap] " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage" << std::endl;
		this->energy_point--;
	}
	else
		std::cout << "[ClapTrap] " << this->name << " has no energy or hp" << std::endl; 
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->hit_point)
	{
		std::cout << "[ClapTrap] " << this->name << " has no hp" << std::endl;
		return ;
	}
	if (amount > this->hit_point)
		this->hit_point = 0;
	else
		this->hit_point -= amount;
	std::cout << "[ClapTrap] take(s) " << amount << " of attack" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_point > 0 && this->energy_point > 0)
	{
		std::cout << "[ClapTrap] is repaired " << amount <<" hp" << std::endl;
		this->hit_point += amount;
		this->energy_point--;
	}
	else
		std::cout << "[ClapTrap] " << this->name << " has no energy or hp" << std::endl;
}