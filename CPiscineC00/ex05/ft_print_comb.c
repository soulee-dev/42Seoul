/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:13:13 by soulee            #+#    #+#             */
/*   Updated: 2022/08/26 03:16:19 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	str[4];

	str[0] = '0';
	while (str[0] <= '7')
	{
		str[1] = (char)(str[0] + 1);
		while (str[1] <= '8')
		{
			str[2] = (char)(str[1] + 1);
			while (str[2] <= '9')
			{
				write(1, &str, 4);
				str[2]++;
				if (str[0] != '7')
				{
					write(1, " ", 1);
				}
			}
			str[1]++;
		}
		str[0]++;
	}
}
