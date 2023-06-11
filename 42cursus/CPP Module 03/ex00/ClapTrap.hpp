/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:56:47 by soulee            #+#    #+#             */
/*   Updated: 2023/06/11 12:01:49 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CALPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	private:
		std::string	name;
		int	hit_point;
		int	energy_point;
		int	attack_damage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& ref);
		~ClapTrap();

		ClapTrap&	operator=(const ClapTrap &ref);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
}


#endif