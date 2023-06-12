/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:43:52 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 13:12:07 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main()
{
	FragTrap	a("a");
	FragTrap	b("b");
	FragTrap	c;

	c = b;

	a.attack("b");
	a.highFivesGuys();
	b.takeDamage(10);
	b.beRepaired(10);
	b.attack("a");
	c.attack("b");
}