/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:16:06 by soulee            #+#    #+#             */
/*   Updated: 2022/09/14 16:51:49 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	do_op(char operator, int a, int b)
{
	int	(*operation[5])(int, int);

	operation[0] = ft_add;
	operation[1] = ft_sub;
	operation[2] = ft_div;
	operation[3] = ft_multi;
	operation[4] = ft_mod;
	if (operator == '+')
		return (operation[0](a, b));
	else if (operator == '-')
		return (operation[1](a, b));
	else if (operator == '/')
		return (operation[2](a, b));
	else if (operator == '*')
		return (operation[3](a, b));
	else if (operator == '%')
		return (operation[4](a, b));
	return (1);
}

int	main(int argc, char *argv[])
{
	int	a;
	int	b;

	if (argc == 4)
	{
		argv++;
		if (argv[1][0] == '+' || argv[1][0] == '-'
				|| argv[1][0] == '/' || argv[1][0] == '%' || argv[1][0] == '*')
		{
			a = ft_atoi(argv[0]);
			b = ft_atoi(argv[2]);
			if (argv[1][0] == '/' && b == 0)
				ft_putstr("Stop : division by zero\n");
			else if (argv[1][0] == '%' && b == 0)
				ft_putstr("Stop : modulo by zero\n");
			else
			{
				ft_putnbr(do_op(argv[1][0], a, b));
				ft_putstr("\n");
			}
		}
		else
			ft_putstr("0\n");
	}
	return (0);
}
