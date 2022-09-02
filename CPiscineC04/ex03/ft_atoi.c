/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:10:20 by soulee            #+#    #+#             */
/*   Updated: 2022/09/03 03:05:38 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*remove_space(char *str)
{
	while (*str != '\0')
	{
		if (((int)(*str) >= 9 && (int)(*str) <= 13)|| (int)(*str) == 32)
			str++;
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
			num = num * 10 + (*str - '0');
			str++;
		}
		else
			return (num);
	}
	return (num * (*sign));
}
