/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:43:36 by soulee            #+#    #+#             */
/*   Updated: 2022/08/24 18:39:13 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	str[128];
	int		count;
	int		tmp;

	count = 0;
	tmp = nb;
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	while (tmp != 0)
	{
		count++;
		tmp /= 10;
	}
	tmp = count;
	while (tmp != 0)
	{
		str[tmp] = nb % 10 + '0';
		nb /= 10;
		tmp --;
	}
	write(1, str, count + 1);
}
