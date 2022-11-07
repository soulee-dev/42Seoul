/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:07:06 by soulee            #+#    #+#             */
/*   Updated: 2022/09/02 23:08:22 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i] != 0)
	{
		if (flag == 1 && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= ('a' - 'A');
		else if (flag == 0 && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += ('a' - 'A');
		if (str[i] < '0' || (str[i] > '9' && str[i] < 'A')
			|| (str[i] > 'Z' && str[i] < 'a') || str[i] > 122)
			flag = 1;
		else
			flag = 0;
		i++;
	}
	return (str);
}
