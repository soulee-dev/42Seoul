/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 01:37:10 by soulee            #+#    #+#             */
/*   Updated: 2022/09/01 01:47:24 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	long long	count;

	count = 0;
	while (*str++ != '\0')
		count++;
	return (count);
}

int	ft_sqaure(unsigned int n, unsigned int base)
{
	long long	x;

	x = 1;
	while (n--)
		x *= base;
	return (x);
}

int	is_valid_base(char *base)
{
	long long	i;
	long long	j;
	long long	length_base;

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
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	long long	n_base;
	long long	n;
	long long	i;
	long long	length_str;
	int			sign;

	i = 0;
	n = 0;
	sign = 1;
	if (is_valid_base(base) == 0)
		return (0);
	n_base = ft_strlen(base);
	length_str = ft_strlen(str);
	if (str[0] == '-')
	{
		sign *= -1;
		i = 1;
	}
	while (i < length_str)
	{
		n = n + ft_find_str(base, str[i])
			* ft_sqaure(length_str - i - 1, n_base);
		i++;
	}
	return ((int)(n * sign));
}
