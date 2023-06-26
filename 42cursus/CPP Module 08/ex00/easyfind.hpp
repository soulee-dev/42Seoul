/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:31:16 by soulee            #+#    #+#             */
/*   Updated: 2023/06/27 01:41:00 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>

template <typename T>
typename	T::iterator	easyfind(T& container, int val)
{
	typename T::iterator	iter;
	
	iter = std::find(container.begin(), container.end(), val);
	if (iter == container.end())
		throw std::runtime_error("Value is not in Container");
	return (iter);
}

#endif