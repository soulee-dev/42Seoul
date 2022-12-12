/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:32:21 by soulee            #+#    #+#             */
/*   Updated: 2022/12/12 20:02:38 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}

int	ft_print_percent(void)
{
	ft_putchr('%');
	return (1);
}

void	ft_putnbr_base(int base, long long nbr, int *count, char *base_text)
{
	if (nbr < 0)
	{
		(*count)++;
		ft_putchr('-');
		nbr = -nbr;
	}
	if (nbr >= (long long)base)
	{
		ft_putnbr_base(base, nbr / base, count, base_text);
		ft_putnbr_base(base, nbr % base, count, base_text);
	}
	else
	{
		(*count)++;
		ft_putchr(base_text[nbr]);
	}
}

void	ft_putnbr_base_unsigned(int base, size_t nbr,
			int *count, char *base_text)
{
	if (nbr >= (size_t)base)
	{
		ft_putnbr_base(base, nbr / base, count, base_text);
		ft_putnbr_base(base, nbr % base, count, base_text);
	}
	else
	{
		(*count)++;
		ft_putchr(base_text[nbr]);
	}
}
