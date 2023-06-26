/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:19:11 by soulee            #+#    #+#             */
/*   Updated: 2023/06/26 21:51:47 by soulee           ###   ########.fr       */
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

void	iter(const T *arr, size_t length, void(*fn)(const T&))
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