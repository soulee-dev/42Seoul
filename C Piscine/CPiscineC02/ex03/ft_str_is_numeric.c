/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:11:45 by soulee            #+#    #+#             */
/*   Updated: 2022/08/27 01:04:10 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	result;

	result = 1;
	while (*str != 0)
	{
		if (!(*str >= 48 && *str <= 57))
		{
			result = 0;
		}
		str++;
	}
	return (result);
}
