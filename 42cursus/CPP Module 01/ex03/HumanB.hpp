#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
private:
	std::string	name;
	Weapon		*weapon;
public:
	HumanB(std::string name);
	void	setWeapon(Weapon &weapon);
	void	attack();
};

HumanB::HumanB(std::string name) : name(name)
{

}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with thier " << this->weapon->getType() << std::endl; 
}

#endif