/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:01:52 by soulee            #+#    #+#             */
/*   Updated: 2023/04/24 21:04:27 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string	hello;
	hello = "HI THIS IS BRAIN";

	std::string	&stringPTR;
	std::string	&stringREF;
	
	cout << &hello;
	return (1);
}