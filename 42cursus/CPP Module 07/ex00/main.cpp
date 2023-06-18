/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:05:52 by soulee            #+#    #+#             */
/*   Updated: 2023/06/18 21:13:03 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int	main(void)
{
	int	a = 5;
	int	b = 7;

	std::cout << a << " : " << b << std::endl;
	std::cout << max(a, b) << min(a, b) << std::endl;
	swap(a, b);
	std::cout << a << " : " << b << std::endl;
	return (0);
}