/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 01:37:10 by soulee            #+#    #+#             */
/*   Updated: 2022/08/31 02:18:29 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (*str++ != '\0')
		count++;
	return (count);
}

int	ft_sqaure(unsigned int n, unsigned int base)
{
	unsigned int	x;

	x = 1;
	while (n--)
		x *= base;
	return (x);
}

int	is_valid_base(char *base)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	length_base;

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

int	ft_find_str(char *str, char c)
{
	unsigned int	idx;

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
	unsigned int	n_base;
	unsigned int	n;
	unsigned int	i;
	unsigned int	length_str;

	i = 0;
	n = 0;
	if (is_valid_base(base) == 0)
		return (0);
	n_base = ft_strlen(base);
	length_str = ft_strlen(str);
	while (i < length_str)
	{
		n = n + ft_find_str(base, str[i])
			* ft_sqaure(length_str - i - 1, n_base);
		i++;
	}
	return ((int)n);
}
