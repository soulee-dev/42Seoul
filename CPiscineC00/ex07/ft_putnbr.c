/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:43:36 by soulee            #+#    #+#             */
/*   Updated: 2022/08/26 22:38:24 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchr(char c)
{
	write(1, &c, 1);
}

void	ft_print_reverse(char str[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putchr(str[size - i - 1]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int		i;
	char	str[30];

	i = 0;
	while (nb != 0)
	{
		str[i++] = nb % 10 + '0';
		nb /= 10;
	}
	ft_print_reverse(str, i);
}
