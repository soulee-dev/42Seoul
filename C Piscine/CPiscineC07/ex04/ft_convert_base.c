/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 03:16:54 by soulee            #+#    #+#             */
/*   Updated: 2022/09/15 03:22:52 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_base_check(char *base);
int		ft_atoi_check(char *base, char c);
char	*remove_spaces(char *str, int *m);
char	*ft_final(int size, long long re, char *str);
int		ft_base_len(char *base);

char	*ft_putnbr(long long nbr, char *base, int i, char *re)
{
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		ft_putnbr(nbr, base, i, re);
	}
	else if (nbr < base_len)
		re[i] = base[nbr];
	else if (nbr >= base_len)
	{
		ft_putnbr(nbr / base_len, base, i + 1, re);
		ft_putnbr(nbr % base_len, base, i, re);
	}
	return (re);
}

long long	ft_atoi(char *base_from, char *base_to, char *nbr, long long base)
{
	int			sign;
	int			i;
	long long	re;

	re = 0;
	i = 0;
	sign = 1;
	if (ft_base_check(base_from) && ft_base_check(base_to))
	{
		nbr = remove_spaces(nbr, &sign);
		while (nbr[i])
		{
			if (ft_atoi_check(base_from, nbr[i]) >= 0)
				re = re * base + ft_atoi_check(base_from, nbr[i]);
			else
				break ;
			i++;
		}
	}
	return (re * sign);
}

char	*ft_itoa(long long base_len2, long long re, char *base_to)
{
	int			size;
	long long	re_re;
	char		*str;
	char		*str_1;

	size = 1;
	if (re < 0)
		re_re = -re;
	else
		re_re = re;
	while (re_re / base_len2 > 0)
	{
		re_re = re_re / base_len2;
		size++;
	}
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	str = ft_putnbr((long long)(re), base_to, 0, str);
	str_1 = ft_final(size, re, str);
	return (str_1);
}

char	*ft_final(int size, long long re, char *str)
{
	char	*str_1;
	int		j;

	j = 0;
	if (re < 0)
		str_1 = (char *)malloc(sizeof(char) * (size + 2));
	else
		str_1 = (char *)malloc(sizeof(char) * (size + 1));
	if (re < 0)
	{
		str_1[0] = '-';
		j++;
	}
	while (size - 1 >= 0)
	{
		str_1[j] = str[size - 1];
		j++;
		size --;
	}
	str_1[j] = 0;
	return (str_1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	base_len1;
	long long	base_len2;
	long long	re;
	char		*str;

	if (!nbr || !base_from || !base_to)
		return (0);
	re = 0;
	base_len1 = ft_base_len(base_from);
	base_len2 = ft_base_len(base_to);
	if (base_len1 < 2 || base_len2 < 2)
		return (0);
	if (!(ft_base_check(base_from) && ft_base_check(base_to)))
		return (0);
	re = ft_atoi(base_from, base_to, nbr, base_len1);
	str = ft_itoa(base_len2, re, base_to);
	return (str);
}
