/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:31:58 by soulee            #+#    #+#             */
/*   Updated: 2023/06/18 21:04:23 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	switch (rand() % 3)
	{
		case 0:
		{
			std::cout << "Create A" << std::endl;
			return (new A());
		}
		case 1:
		{
			std::cout << "Create B" << std::endl;
			return (new B());
		}
		case 2:
		{
			std::cout << "Create C" << std::endl;
			return (new C());
		}
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Ptr is A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "Ptr is B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "Ptr is C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A&	a = dynamic_cast<A&>(p);
		std::cout << "Ref is A" << std::endl;
		static_cast<void>(a);
	}
	catch (...) {}

	try
	{
		B&	b = dynamic_cast<B&>(p);
		std::cout << "Ref is B" << std::endl;
		static_cast<void>(b);
	}
	catch (...) {}

	try
	{
		C&	c = dynamic_cast<C&>(p);
		std::cout << "Ref is C" << std::endl;
		static_cast<void>(c);
	}
	catch (...) {}
}

void	check_leaks()
{
	system("leaks identify");
}

int	main()
{
	Base*	ptr_one;
	Base*	ptr_two;
	Base*	ptr_three;

	atexit(check_leaks);
	ptr_one = generate();
	ptr_two = generate();
	ptr_three = generate();

	identify(ptr_one);
	identify(*ptr_two);
	identify(*ptr_three);

	delete ptr_one;
	delete ptr_two;
	delete ptr_three;


	return (0);
}