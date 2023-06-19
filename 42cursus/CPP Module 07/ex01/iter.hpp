/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:19:11 by soulee            #+#    #+#             */
/*   Updated: 2023/06/19 13:12:21 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>

void	iter(T *arr, size_t length, void(*fn)(T&))
{
	for (size_t i = 0; i < length; i++)
		fn(arr[i]);
}


template<typename T>

void	print(T& s)
{
	std::cout << s << " ";
}

#endif