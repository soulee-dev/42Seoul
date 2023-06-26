/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:35:57 by soulee            #+#    #+#             */
/*   Updated: 2023/06/27 01:37:17 by soulee           ###   ########.fr       */
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
	std::cout << "[Span] Overloaded assignmnet operator" << std::endl;
	if (this != &ref)
	{
		this->storage = ref.storage;
		this->N = ref.N;
	}
	return (*this);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) > this->N)
		throw std::logic_error("Error: Vector is full");
	this->storage.insert(this->storage.end(), begin, end);
}

void	Span::addNumber(const int val)
{
	if (this->storage.size() < this->storage.capacity())
		this->storage.push_back(val);
	else
		throw std::logic_error("Error: Vector is full");
}

int	Span::shortestSpan(void)
{
	if (this->storage.size() < 2)
		throw std::logic_error("Error: Less than two elements");

	int 				min = INT_MAX;
	std::vector<int>	v(this->storage);

	sort(v.begin(), v.end());
	for (std::size_t i = 0; i < v.size() - 1; i++)
	{
		int	diff = v[i + 1] - v[i];
		if (min > diff)
			min = diff;
	}
	return (min);
}

int	Span::longestSpan(void)
{
	if (this->storage.size() < 2)
		throw std::logic_error("Error: Less than two elements");

	std::vector<int>	v(this->storage);
	sort(v.begin(), (v.end()));
	return (*(v.end() - 1) - *(v.begin()));
}