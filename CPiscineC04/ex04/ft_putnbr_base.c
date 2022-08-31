/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:10:51 by soulee            #+#    #+#             */
/*   Updated: 2022/08/31 23:04:50 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++ != '\0')
		count++;
	return (count);
}

void	ft_putchr(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_to_n_base(int decimal, int n_base, char *base)
{
	char			result[100];
	long long		mod;
	long long		i;

	i = 0;
	while (1)
	{
		mod = decimal % n_base;
		if (mod < n_base)
			result[i] = base[mod];
		decimal /= n_base;
		i++;
		if (decimal == 0)
			break ;
	}
	i = i - 1;
	while (i >= 0)
	{
		ft_putchr(result[i]);
		i--;
	}
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;
	int	length_base;

	length_base = ft_strlen(base);
	if (length_base < 2)
		return (0);
	i = 0;
	while (i < length_base)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < length_base)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	n_base;

	if (is_valid_base(base) == 0)
		return ;
	n_base = ft_strlen(base);
	if (nbr == -2147483648)
	{
		ft_putchr('-');
		ft_putstr_to_n_base(-(nbr / n_base), n_base, base);
		ft_putchr(base[nbr % n_base]);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchr('-');
		nbr = -nbr;
	}
	ft_putstr_to_n_base(nbr, n_base, base);
}
