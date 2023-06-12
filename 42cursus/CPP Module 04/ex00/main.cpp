/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:31:30 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 17:08:15 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void	check_leaks()
{
	system("leaks polymorphism");
}

int	main()
{
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog("i: Golden retriever");
	const Animal*	i = new Cat("j: Domestic Korean Short Hair");
	const WrongAnimal*	wrong = new WrongCat("peww");


	atexit(check_leaks);
	std::cout << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();

	std::cout << j->getType() << " " << std::endl;
	j->makeSound();

	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();

	std::cout << std::endl;
	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound();

	std::cout << std::endl;
	delete meta;
	meta = NULL;

	delete j;
	j = NULL;

	delete i;
	i = NULL;

	delete wrong;
	wrong = NULL;

	return (0);
}