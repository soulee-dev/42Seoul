/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:43:52 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 13:06:43 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	a("a");
	ScavTrap	b("b");
	ScavTrap	c;

	c = b;

	a.attack("b");
	a.guardGate();
	b.takeDamage(10);
	b.beRepaired(10);
	b.attack("a");
	c.attack("b");
}