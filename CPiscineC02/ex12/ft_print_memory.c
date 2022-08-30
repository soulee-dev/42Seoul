/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:20:48 by soulee            #+#    #+#             */
/*   Updated: 2022/08/30 17:01:43 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_put_str(char str[])
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putstr_to_hex(unsigned long long decimal)
{
	char		hex[10];
	long long	mod;
	long long	i;
	long long	j;

	i = 0;
	while (1)
	{
		mod = decimal % 16;
		if (mod < 10)
			hex[i++] = mod + '0';
		else
			hex[i++] = (mod - 10) + 'a';
		decimal /= 16;
		if (decimal == 0)
			break ;
	}
	j = i - 1;
	if (i == 1)
		ft_put_str("0");
	while (j >= 0)
	{
		write(1, &hex[j--], 1);
	}
}

void	ft_print_data_line(char *str, int i)
{
	int	j;
	int	count;

	count = 0;
	ft_put_str("0000000");
	ft_putstr_to_hex((unsigned long long)(str + i * 16));
	j = 0;
	ft_put_str(": ");
	while (j < 16)
	{
		if (str[i * 16 + j] == 0)
			break ;
		ft_putstr_to_hex(*(str + i * 16 + j));
		count += 2;
		if ((j + 1) % 2 == 0)
		{
			ft_put_str(" ");
			count++;
		}
		j++;
	}
	j = -1;
	while (++j < 40 - count)
		ft_put_str(" ");
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char				*str;
	unsigned int		i;
	unsigned int		j;

	i = -1;
	str = (char *)addr;
	if (size % 16 > 0)
		size = (size - size % 16) + 16;
	while (++i < size / 16)
	{
		ft_print_data_line(str, i);
		j = 0;
		while (j < 16)
		{
			if (str[i * 16 + j] == 0)
				break ;
			if (str[i * 16 + j] >= 32 && str[i * 16 + j] != 127)
				write(1, &str[i * 16 + j], 1);
			else
				ft_put_str(".");
			j++;
		}
		ft_put_str("\n");
	}
	return (addr);
}
