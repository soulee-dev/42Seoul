/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:36:22 by soulee            #+#    #+#             */
/*   Updated: 2022/08/27 00:37:07 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchr(char c)
{
	write(1, &c, 1);
}

void	ft_put_reverse(char str[], int size)
{
	int	j;

	ft_putchr('\\');
	if (size == 1)
		ft_putchr('0');
	j = size - 1;
	while (j >= 0)
	{
		ft_putchr(str[j]);
		j--;
	}
}

void	ft_putstr_to_hex(int decimal)
{
	char	hex[10];
	int		mod;
	int		i;

	i = 0;
	while (1)
	{
		mod = decimal % 16;
		if (mod < 10)
			hex[i] = mod + '0';
		else
			hex[i] = (mod - 10) + 'a';
		decimal /= 16;
		i++;
		if (decimal == 0)
			break ;
	}
	ft_put_reverse(hex, i);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != 0)
	{
		if (*str >= 0 && *str <= 31)
			ft_putstr_to_hex(*str);
		else
			ft_putchr(*str);
		str++;
	}
}
