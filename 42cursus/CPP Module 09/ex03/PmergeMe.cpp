/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:43:27 by soulee            #+#    #+#             */
/*   Updated: 2023/06/28 13:25:30 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool				comparePair(const Pair &a, const Pair &b)
{
	return (a.first < b.first);
}

PmergeMe::PmergeMe()
{	
}

PmergeMe::PmergeMe(const PmergeMe& ref)
{
	*this = ref;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& ref)
{
	static_cast<void>(ref);
	return (*this);
}

std::vector<int>	PmergeMe::vectorMergeInsertionSort(std::vector<int> X)
{
	int	n = X.size();
	std::vector<Pair>	pairs;

	for (int i = 0; i < n / 2; i++)
	{
		Pair	p;

		p = std::make_pair(std::min(X[i * 2], X[i * 2 + 1]), std::max(X[i * 2], X[i * 2 + 1]));
		pairs.push_back(p);
	}
	
	if (n % 2 == 1)
		pairs.push_back(std::make_pair(X[n - 1], X[n - 1]));
	
	std::sort(pairs.begin(), pairs.end(), comparePair);

	std::vector<int>	S;
	for (std::size_t i = 0; i < pairs.size(); i++)
		S.push_back(pairs[i].first);
	
	for (std::size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first == pairs[i].second)
			continue;
		std::vector<int>::iterator	pos;
		pos = std::lower_bound(S.begin(), S.end(), pairs[i].second);
		S.insert(pos, pairs[i].second);
	}
	return (S);
}

std::list<int>	PmergeMe::listMergeInsertionSort(std::list<int> X)
{
	int	n = X.size();
	std::list<Pair>	pairs;

	std::list<int>::iterator	it = X.begin();
	for (int i = 0; i < n / 2; i++)
	{
		Pair	p;

		p = std::make_pair(std::min(*it, *(std::next(it))), std::max(*it, *(std::next(it))));
		pairs.push_back(p);
		std::advance(it, 2);
	}
	
	if (n % 2 == 1)
		pairs.push_back(std::make_pair(*it, *it));
	
	pairs.sort(comparePair);

	std::list<int>	S;
	for (std::list<Pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
		S.push_back(it->first);
	
	for (std::list<Pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if (it->first == it->second)
			continue;
		std::list<int>::iterator	pos;
		pos = std::lower_bound(S.begin(), S.end(), it->second);
		S.insert(pos, it->second);
	}
	return (S);
}
