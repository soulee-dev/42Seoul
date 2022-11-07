/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:57:17 by soulee            #+#    #+#             */
/*   Updated: 2022/08/27 17:19:50 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putline(int x, char str[])
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(str[0]);
		else if (i < x - 1)
			ft_putchar(str[1]);
		else
			ft_putchar(str[2]);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int		i;

	i = 0;
	while (i < y)
	{
		if (i == 0)
			ft_putline(x, "ABC");
		else if (i < y - 1)
			ft_putline(x, "B B");
		else
			ft_putline(x, "ABC");
		i ++;
	}
}
