/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:16:14 by soulee            #+#    #+#             */
/*   Updated: 2022/08/25 18:19:12 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	result;

	result = 1;

	while (*str != 0)
	{
		if (!(*str >= 97 && *str <= 122))
		{
			result = 0;
		}
		str++;
	}

	return (result);
}
