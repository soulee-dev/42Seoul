/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:35:57 by soulee            #+#    #+#             */
/*   Updated: 2023/06/26 23:19:31 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : N(10)
{
	std::cout << "[Span] Default constructor" << std::endl;
	this->storage.reserve(this->N);
}

Span::Span(unsigned int N) : N(N)
{
	std::cout << "[Span] Parameterized constructor" << std::endl;
	this->storage.reserve(this->N);
}

Span::Span(const Span& ref)
{
	std::cout << "[Span] Copy constructor" << std::endl;
	*this = ref;
}

Span::~Span()
{
	std::cout << "[Span] Destructor" << std::endl;
}

Span&	Span::operator=(const Span& ref)
{
	if (this != &ref) {
		std::vector<int>	tmp(ref.storage);
		storage = tmp;
		N = ref.N;
	}
	return (*this);
}

void	Span::addNumber(const int val)
{
	storage.push_back(val);
}

int	Span::shortestSpan(void)
{
	// for문을 돌면서 두 값의 차가 가장 작은 것
	int min = 2147483647;
	sort(storage.begin(), storage.end());
	for (std::size_t i = 0; i < storage.size() - 1; i++)
	{
		int	diff = storage[i + 1] - storage[i];
		if (min > diff)
			min = diff;
	}

	// for (std::vector<int>::iterator it = storage.begin(); it != storage.end() - 1; it++)
	// {
	// 	int diff = *(it + 1) - *it;
	// 	if (min > diff)
	// 		min = diff;
	// }
	return (min);
}

int	Span::longestSpan(void)
{
	// 가장 큰  값값과  작작은  값값의   차
	sort(storage.begin(), storage.end());
	return (*(storage.end() - 1) - *storage.begin());
}