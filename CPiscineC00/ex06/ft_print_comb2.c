/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:51:04 by soulee            #+#    #+#             */
/*   Updated: 2022/08/24 21:55:59 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_comb2(void)
{
	char	str[8];

	str[2] = ' ';
	str[6] = 1;
	while (str[6] < 99)
	{
		str[7] = 0;
		while (str[7] < 100)
		{
			str[0] = str[6] / 10 + '0';
			str[1] = str[6] % 10 + '0';
			str[3] = str[7] / 10 + '0';
			str[4] = str[7] % 10 + '0';
			write(1, str, 5);
			if (str[0] != '9' || str[1] != '8' || str[3] != '9' || str[4] != '9')
			{
				write(1, ", ", 2);
			}
			str[7]++;
		}
		str[6]++;
	}
}

// int main() {
// 	ft_print_comb2();
// 	return 0;
// }
