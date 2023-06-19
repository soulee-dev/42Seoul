/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:19:14 by soulee            #+#    #+#             */
/*   Updated: 2023/06/19 13:13:26 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int	main(void)
{
	int	a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	iter(a, sizeof(a) / sizeof(*a), print);
	std::cout << std::endl;

	char	b[6] = "Hello";
	iter(b, sizeof(b) / sizeof(*b), print);
	std::cout << std::endl;

	return (0);
}