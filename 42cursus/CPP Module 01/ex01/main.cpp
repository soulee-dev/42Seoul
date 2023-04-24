/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:19:26 by soulee            #+#    #+#             */
/*   Updated: 2023/04/24 20:39:45 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie*	zombies = zombieHorde(3, "Soulee");

	for (int i = 0; i < 3; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;

	return (0);
}