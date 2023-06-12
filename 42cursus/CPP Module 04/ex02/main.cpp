/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:58:07 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 20:01:31 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

void	check_leaks()
{
	system("leaks abstract_class");
}

int	main()
{
	// const Animal	*meta = new Animal();
	const Animal*	j = new Dog("i: Golden retriever");
	const Animal*	i = new Cat("j: Domestic Korean Short Hair");

	atexit(check_leaks);
	std::cout << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();

	std::cout << j->getType() << " " << std::endl;
	j->makeSound();

	delete j;
	j = NULL;

	delete i;
	i = NULL;
	return (0);
}