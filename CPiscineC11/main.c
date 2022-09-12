/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:09:06 by soulee            #+#    #+#             */
/*   Updated: 2022/09/09 19:19:33 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ex00/ft_foreach.c"
#include "ex01/ft_map.c"

void	ft_putnbr(int decimal)
{
	printf("%d\n", decimal);
}

int	ft_add_one(int decimal)
{
	return (decimal + 1);
}

void	print_list(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}

int	main(void)
{
	// ex00
	int	tab00[5] = {1, 2, 3, 4, 5};
	ft_foreach(tab00, 5, &ft_putnbr);

	print_list(ft_map(tab00, 5, &ft_add_one), 5);
	return (0);
}