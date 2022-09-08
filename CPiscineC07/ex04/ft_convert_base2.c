/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 00:04:34 by soulee            #+#    #+#             */
/*   Updated: 2022/09/09 03:23:50 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_ft_strlen(char *str)
{
	long long	count;

	count = 0;
	while (*str++ != '\0')
		count++;
	return (count);
}

int	ft_find_str(char *str, char c)
{
	long long	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}

int	is_valid_base(char *base)
{
	long long	i;
	long long	j;
	long long	length_base;

	length_base = ft_ft_strlen(base);
	if (length_base < 2)
		return (0);
	i = 0;
	while (i < length_base)
	{
		if (base[i] == '+' || base[i] == '-' || (base[i] >= 9 && base[i] <= 13)
			|| base[i] == 32)
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

char	*ft_remove_sign(char *str, int *sign)
{
	*sign = 1;
	while (*str != '\0')
	{
		if (((int)(*str) >= 9 && (int)(*str) <= 13) || (int)(*str) == 32)
			str++;
		else
			break ;
	}
	while (*str != '\0')
	{
		if (*str == '-')
		{
			*sign *= -1;
			str++;
		}
		else if (*str == '+')
			str++;
		else
			return (str);
	}
	return (str);
}

void	ft_putstr_to_n_base(char *str, int decimal, int n_base, char *base)
{
	if (decimal >= n_base)
	{
		ft_putstr_to_n_base(str, decimal / n_base, n_base, base);
		ft_putstr_to_n_base(str, decimal % n_base, n_base, base);
	}
	else
		str[(int)(str[0]++)] = base[decimal];
}
