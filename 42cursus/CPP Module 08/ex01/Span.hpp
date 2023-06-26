/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:36:13 by soulee            #+#    #+#             */
/*   Updated: 2023/06/26 22:58:46 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
	private:
		std::vector<int>	storage;
		unsigned int		N;
	public:
		Span(void);
		Span(const unsigned int N);
		
		Span(const Span& ref);
		~Span();

		Span&			operator=(const Span& ref);
		
		void			addNumber(const int val);
		int	shortestSpan(void);
		int	longestSpan(void);
};

#endif