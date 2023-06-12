/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:31:30 by soulee            #+#    #+#             */
/*   Updated: 2023/06/12 19:47:01 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void	check_leaks()
{
	system("leaks brains");
}

int	main()
{
	// std::string	str;
	// Animal	*meta[10];

	// atexit(check_leaks);


	// for (size_t i = 0; i < 10; i++)
	// {
	// 	if (i % 2)
	// 		meta[i] = new Dog();
	// 	else
	// 		meta[i] = new Cat();
	// }
	// std::cout << std::endl;

	// for (size_t i = 0; i < 10; i++)
	// 	delete meta[i];

	// std::cout << std::endl;
	// std::cout << std::endl;
	// std::cout << std::endl;
	// std::cout << std::endl;

	// const Dog*	x = new Dog();
	// const Cat*	y = new Cat();

	// std::cout << x->getIdea(0) << std::endl;
	// std::cout << y->getIdea(0) << std::endl;

	// delete x;
	// delete y;

	// std::cout << std::endl;
	// std::cout << std::endl;
	// std::cout << std::endl;
	// std::cout << std::endl;

	Dog*	k = new Dog();
	Dog*	l = new Dog();

	k->setIdea("Hello World", 0);
	std::cout << "Dog k idea[0]: " << k->getIdea(0) << std::endl;

	*l = *k;
	std::cout << "Dog l idea[0]: " << l->getIdea(0) << std::endl;
	
	k->setIdea("Hello World2", 0);
	std::cout << "Dog k idea[0]: " << k->getIdea(0) << std::endl;

	std::cout << "Dog l idea[0]: " << l->getIdea(0) << std::endl;

	delete k;
	k = NULL;

	delete l;
	l = NULL;

	return (0);
}