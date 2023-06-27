/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:57:54 by soulee            #+#    #+#             */
/*   Updated: 2023/06/27 22:22:49 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <stack>

class RPN
{
	private:
		bool	isOperator(const std::string str);
		void	checkInput(const std::string str);
		double	calculate(char op, double a, double b);
	public:
		RPN(void);
		RPN(const RPN& ref);
		~RPN();

		RPN&	operator=(const RPN& ref);

		void	run(const char *str);
};

#endif