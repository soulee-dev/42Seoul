/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:08:24 by soulee            #+#    #+#             */
/*   Updated: 2023/06/18 21:11:24 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>

void	swap(T& a, T& b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}


template<typename U>

const U&	min(const U& a, const U& b)
{
	return (a <= b ? a : b);
}

template<typename V>

const V&	max(const V& a, const V& b)
{
	return (a >= b ? a : b);
}


