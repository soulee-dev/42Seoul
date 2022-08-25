/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:43:36 by soulee            #+#    #+#             */
/*   Updated: 2022/08/25 00:38:06 by soulee           ###   ########.fr       */
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
	if (nb == 0)
	{
		write(1, "0", 1);
	}
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
		str[tmp--] = nb % 10 + '0';
		nb /= 10;
	}
	write(1, str, count + 1);
}

void main()
{
	ft_putnbr(-2147483647);
}