/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:16:06 by soulee            #+#    #+#             */
/*   Updated: 2022/09/12 04:09:57 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str);

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	do_op(char operator, char *arg1, char *arg2)
{
	int	a;
	int	b;

	a = ft_atoi(arg1);
	b = ft_atoi(arg2);
	if (operator == '/' && b == 0)
		ft_putstr("Stop : division by zero");
	else if (operator == '%' && b == 0)
		ft_putstr("Stop : modulo by zero");
}

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		argv++;
		if (argv[1][0] == '+' || argv[1][0] == '-'
			|| argv[1][0] == '/' || argv[1][0] == '%')
		{
			do_op(argv[1][0], argv[0], argv[2]);
		}
		else
		{
			ft_putstr("0");
			return (1);
		}
	}
	else
		return (1);
}

int	mod(int a, int b)
{
	return (a % b);
}

int	div(int a, int b)
{
	return (a / b);
}