/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:20:48 by soulee            #+#    #+#             */
/*   Updated: 2022/08/28 23:13:12 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchr(char c)
{
	write(1, &c, 1);
}

void	ft_put_str(char str[])
{
	while (*str)
		ft_putchr(*str++);
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
			hex[i] = mod + '0';
		else
			hex[i] = (mod - 10) + 'a';
		decimal /= 16;
		i++;
		if (decimal == 0)
			break ;
	}
	j = i - 1;
	while (j >= 0)
	{
		ft_putchr(hex[j]);
		j--;
	}
}

int	ft_strlen(char *str)
{
	int	count;

	while (*str++)
		count++;
	return (count);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)addr;
	while (i < size / 16)
	{
		ft_put_str("0000000");
		ft_putstr_to_hex((unsigned long long)(str + i * 16));
		j = 0;
		ft_put_str(": ");
		while (j < 16)
		{
			ft_putstr_to_hex(*(str + i * 16 + j));
			if ((j + 1) % 2 == 0)
			{
				ft_putchr(' ');
			}
			j++;
		}
		j = 0;
		while (j < 16)
		{
			ft_putchr(*(str + i * 16 + j));
			j++;
		}
		ft_put_str("\n");
		i++;
	}
}

int	main()
{
	char *str = "Bonjour les aminches c'est cool show mem on fait de truc terrible\1\2";

	ft_print_memory(str, ft_strlen(str));
}
