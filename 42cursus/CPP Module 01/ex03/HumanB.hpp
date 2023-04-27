#include "HumanB.hpp"

#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB
{
private:
	std::string	name;
	Weapon	&weapon;
public:
	HumanA(std::string name);
	void	attack();
};

HumanB::HumanB(std::string name) : name(name)
{

}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with thier " << this->weapon.getType() << std::endl; 
}

#endif