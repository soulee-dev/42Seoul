/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:36:22 by soulee            #+#    #+#             */
/*   Updated: 2022/09/06 17:28:38 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchr(unsigned char c)
{
	write(1, &c, 1);
}

void	ft_ft_putstr_to_hex(int decimal, int flag)
{
	char	*base;

	base = "0123456789abcdef";
	if (decimal < 16 && flag == 1)
		ft_putchr('0');
	if (decimal >= 16)
	{
		ft_ft_putstr_to_hex(decimal / 16, 0);
		ft_ft_putstr_to_hex(decimal % 16, 0);
	}
	else
		ft_putchr(base[decimal]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != 0)
	{
		if (*str < 32 || *str == 127)
		{
			ft_putchr('\\');
			ft_ft_putstr_to_hex((unsigned char)*str, 1);
		}
		else
			ft_putchr((unsigned char)*str);
		str++;
	}
}
