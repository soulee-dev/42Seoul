/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:43:25 by soulee            #+#    #+#             */
/*   Updated: 2023/06/28 13:05:18 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <sstream>
# include <iomanip>
# include <ctime>

typedef std::pair<int, int>	Pair;
bool	comparePair(const Pair &a, const Pair &b);

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& ref);
		~PmergeMe();

		PmergeMe&	operator=(const PmergeMe& ref);

		std::vector<int>	vectorMergeInsertionSort(std::vector<int> X);
		std::list<int>		listMergeInsertionSort(std::list<int> X);

};

#endif