/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:58:17 by soulee            #+#    #+#             */
/*   Updated: 2023/06/27 22:36:10 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	
}

RPN::RPN(const RPN& ref)
{
	*this = ref;
}

RPN::~RPN()
{	
}

RPN&	RPN::operator=(const RPN& ref)
{
	static_cast<void>(ref);
	return (*this);
}

bool	RPN::isOperator(const std::string str)
{
	if (str == "+" || str == "-" || str == "/" || str == "*")
		return (true);
	return (false);
}

void	RPN::checkInput(const std::string str)
{
	char	*ptr = NULL;
	if (isOperator(str))
		return ;
	
	double	value = std::strtod(str.c_str(), &ptr);
	if (value == 0.0 && !std::isdigit(str[0]))
		throw std::runtime_error("Error");
	if (*ptr && std::strcmp(ptr, "f"))
		throw std::runtime_error("Error");
	if (value < 0 || value >= 10)
		throw std::runtime_error("Error");
}

double	RPN::calculate(char op, double a, double b)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (b == 0)
		throw std::runtime_error("Error");
	return (a / b);
}

void	RPN::run(const char *str)
{
	std::size_t				count_values = 0;
	std::stack<std::string>	stack_string;
	std::stack<std::string>	stack_tmp;
	std::istringstream		string_stream(str);
	std::string				string_buffer;

	while (std::getline(string_stream, string_buffer, ' '))
	{
		if (string_buffer.empty())
			continue;
		stack_tmp.push(string_buffer);
	} 
	
	while (!stack_tmp.empty())
	{
		if (!isOperator(stack_tmp.top()))
			count_values++;
		stack_string.push(stack_tmp.top());
		checkInput(stack_tmp.top());
		stack_tmp.pop();
	}

	if (count_values * 2 - stack_string.size() != 1)
		throw std::runtime_error("Error");

	std::stack<double>	ret;
	while (!stack_string.empty())
	{
		std::string	tmp = stack_string.top();
		if (isOperator(tmp))
		{
			if (ret.size() < 2)
				throw std::runtime_error("Error");
			double	a, b;
			b = ret.top();
			ret.pop();
			a = ret.top();
			ret.pop();
			ret.push(calculate(tmp[0], a, b));
			stack_string.pop();
		}
		else
		{
			double	value = std::strtod(stack_string.top().c_str(), NULL);

			ret.push(value);
			stack_string.pop();
		}
	}
	std::cout << ret.top() << std::endl;
}