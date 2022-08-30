/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:10:20 by soulee            #+#    #+#             */
/*   Updated: 2022/08/31 03:00:29 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*remove_space(char *str)
{
	while (*str != '\0')
	{
		if (*str == ' ')
		{
			str++;
		}
		else
			return (str);
	}
	return (str);
}

char	*remove_sign(char *str, int *sign)
{
	*sign = 1;
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

int	ft_atoi(char *str)
{
	int	sign;
	int	num;

	num = 0;
	str = remove_space(str);
	str = remove_sign(str, &sign);
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			num = num * 10 + (*str + '0');
			str++;
		}
		else
			return (num);
	}
	return (num);
}

void main()
{
	printf("%c", ft_atoi("1"));
}