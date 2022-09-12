/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:26:45 by soulee            #+#    #+#             */
/*   Updated: 2022/09/13 01:30:04 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

// In case of no one can be done, what should we print out?
int	main(void)
{
	int	i;
	int	j;
	int	**map;

	map = read_dict("map");
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			printf("%c ", map[j][i]);
			j++;
		}
		printf("\n");
		i++;
	}
}
