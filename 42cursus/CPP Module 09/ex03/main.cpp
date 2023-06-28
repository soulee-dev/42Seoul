/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:43:49 by soulee            #+#    #+#             */
/*   Updated: 2023/06/28 13:17:20 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	checkInput(const std::string str)
{
	char	*ptr = NULL;
	double	value = std::strtod(str.c_str(), &ptr);

	if (value == 0.0 && !std::isdigit(str[0]))
		return (false);
	if (*ptr && std::strcmp(ptr, "f"))
		return (false);
	if (value < 0)
		return (false);
	if (value != static_cast<int>(value))
		return (false);
	return (true);
}

int	main(int argc, char *argv[])
{
	PmergeMe			pmergeme;
	std::list<int>		lst;
	std::vector<int>	vec;

	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	for (int i = 1; i < argc; i++)
	{
		std::string			string_tmp(argv[i]);
		std::istringstream	string_stream(string_tmp);
		std::string			string_buffer;
		while (std::getline(string_stream, string_buffer, ' '))
		{
			if (!string_buffer.empty() && !checkInput(string_buffer))
			{
				std::cout << "Error" << std::endl;
				return (1);
			}
			if (string_buffer.empty())
				continue;
			lst.push_back(static_cast<int>(strtod(string_buffer.c_str(), NULL)));
			vec.push_back(static_cast<int>(strtod(string_buffer.c_str(), NULL)));
		}
	}

	std::cout << "Before:   ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i]  << " ";
	}
	std::cout << std::endl;

	clock_t lstStart = clock();
	std::list<int>		sortedLst = pmergeme.listMergeInsertionSort(lst);
	clock_t lstEnd = clock();

	clock_t vecStart = clock();
	std::vector<int>	sortedVec = pmergeme.vectorMergeInsertionSort(vec);
	clock_t vecEnd = clock();

	std::cout << "After:    ";
	for (size_t i = 0; i < sortedVec.size(); i++)
	{
		std::cout << sortedVec[i]  << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << std::setw(4) << lst.size() << " elements with std::list : " << lstEnd - lstStart << "ms" << std::endl;
	std::cout << "Time to process a range of " << std::setw(4) << vec.size() << " elements with std::vector : " << vecEnd - vecStart << "ms" << std::endl;
	return (0);
}
