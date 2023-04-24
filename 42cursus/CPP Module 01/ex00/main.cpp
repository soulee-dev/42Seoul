/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:19:26 by soulee            #+#    #+#             */
/*   Updated: 2023/04/24 20:57:37 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	aZombie("Soulee");
	aZombie.announce();

	Zombie *_newZombie;
	_newZombie = newZombie("Hello Evaluator");
	_newZombie->announce();
	delete _newZombie;

	randomChump("Hahaha");

	return (0);
}