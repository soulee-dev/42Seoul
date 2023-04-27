#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
	std::string	name;
	Weapon	&weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	void	attack();
};

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{

}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with thier " << this->weapon.getType() << std::endl; 
}

#endif