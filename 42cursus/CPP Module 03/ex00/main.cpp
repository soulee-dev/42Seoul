/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:43:52 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 12:39:29 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	a("a");
	ClapTrap	b("b");
	ClapTrap	c;

	c = b;

	a.attack("b");
	b.takeDamage(10);
	b.beRepaired(10);
	b.attack("a");
	c.attack("b");
}