/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 00:04:34 by soulee            #+#    #+#             */
/*   Updated: 2022/09/06 17:53:07 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
	if (decimal >= n_base)
	{
		ft_putstr_to_n_base(decimal / n_base, n_base, base);
		ft_putstr_to_n_base(decimal % n_base, n_base, base);
	}
	else
		printf("%c", base[decimal]);

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
