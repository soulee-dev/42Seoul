/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:10:51 by soulee            #+#    #+#             */
/*   Updated: 2022/09/13 19:27:38 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_ft_ft_strlen(char *str)
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
	if (decimal >= n_base)
	{
		ft_putstr_to_n_base(decimal / n_base, n_base, base);
		ft_putstr_to_n_base(decimal % n_base, n_base, base);
	}
	else
		write(1, &base[decimal], 1);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;
	int	length_base;

	length_base = ft_ft_ft_strlen(base);
	if (length_base < 2)
		return (0);
	i = 0;
	while (i < length_base)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
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
	n_base = ft_ft_ft_strlen(base);
	if (nbr == -2147483648)
	{
		ft_putchr('-');
		ft_putstr_to_n_base(-(nbr / n_base), n_base, base);
		ft_putchr(base[nbr % n_base * -1]);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchr('-');
		nbr = -nbr;
	}
	ft_putstr_to_n_base(nbr, n_base, base);
}
