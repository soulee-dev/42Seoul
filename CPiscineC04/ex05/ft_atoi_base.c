/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 01:37:10 by soulee            #+#    #+#             */
/*   Updated: 2022/09/06 20:37:37 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ft_strlen(char *str)
{
	long long	count;

	count = 0;
	while (*str++ != '\0')
		count++;
	return (count);
}

int	ft_is_valid_base(char *base)
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

int	ft_atoi_base(char *str, char *base)
{
	long long	n_base;
	long long	n;
	long long	i;
	int			sign;

	i = 0;
	n = 0;
	if (ft_is_valid_base(base) == 0)
		return (0);
	n_base = ft_ft_strlen(base);
	str = ft_remove_sign(str, &sign);
	while (*str)
	{
		if (!(*str == '+' || *str == '-' || (*str >= 9 && *str <= 13)
				|| *str == 32))
		{
			n = (n * n_base) + ft_find_str(base, str[i]);
		}
		else
			break ;
		str++;
	}
	return ((int)(n * sign));
}
