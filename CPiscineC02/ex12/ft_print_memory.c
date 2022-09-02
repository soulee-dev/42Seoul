/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 02:33:10 by soulee            #+#    #+#             */
/*   Updated: 2022/09/03 02:51:24 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_str(char str[])
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putstr_to_hex(unsigned long long decimal, int flag)
{
	char	*base;

	base = "0123456789abcdef";
	if (decimal < 16 && flag == 1)
		ft_put_str("0");
	if (decimal >= 16)
	{
		ft_putstr_to_hex(decimal / 16, 0);
		ft_putstr_to_hex(decimal % 16, 0);
	}
	else
		write(1, &base[decimal], 1);
}

void	ft_print_memory_line(unsigned long long str)
{
	unsigned long long	tmp;
	int					j;

	tmp = str;
	j = 1;
	while (j++ < 15)
	{
		if (tmp < 16)
			ft_put_str("0");
		tmp /= 16;
	}
	ft_putstr_to_hex((unsigned long long)str, 0);
}

void	ft_print_data_line(unsigned char *str, int size)
{
	int	i;

	i = -1;
	while (i++ < 16)
	{
		if (i % 2 == 0)
			ft_put_str(" ");
		if (i < size)
			ft_putstr_to_hex((unsigned long long)str[i], 1);
		else if (i != 16)
			ft_put_str("  ");
	}
	i = 0;
	while (i < size - 1)
	{
		if (str[i] <= 31 || str[i] >= 127)
			ft_put_str(".");
		else
			write(1, &str[i], 1);
		i++;
	}
}

void	**ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned int	sendsize;

	i = 0;
	str = addr;
	while (i * 16 < size)
	{
		if (i < size / 16)
			sendsize = 16;
		else
			sendsize = size % 16;
		ft_print_memory_line((unsigned long long)str + (i * 16));
		ft_put_str(":");
		ft_print_data_line(str + (i * 16), sendsize);
		ft_put_str("\n");
		i++;
	}
	return (addr);
}
