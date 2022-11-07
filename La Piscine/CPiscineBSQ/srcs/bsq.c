/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:02:06 by subcho            #+#    #+#             */
/*   Updated: 2022/09/15 11:38:11 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

void	print_bsq(int **map, char *charset, int *max_index, int *xy)
{
	int	i;
	int	j;

	i = 0;
	while (i < xy[1])
	{
		j = 0;
		while (j < xy[0])
		{
			if (map[i][j] == 0)
				write(1, &charset[1], 1);
			else if ((i >= max_index[0] && i <= max_index[2])
				&& (j >= max_index[1] && j <= max_index[3]))
				write(1, &charset[2], 1);
			else
				write(1, &charset[0], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	get_max_index_first(int **map, int *max_index, int *max, int *xy)
{
	int	i;
	int	j;

	i = 0;
	while (i < xy[1])
	{
		j = 0;
		while (j < xy[0])
		{
			if (map[i][j] > *max)
			{
				*max = 1;
				max_index[0] = i;
				max_index[1] = j;
				max_index[2] = i;
				max_index[3] = j;
				break ;
			}
			j++;
		}
		if (*max == 1)
			break ;
		i++;
	}
}

int	*get_max_index(int **map, int max, int *max_index, int *xy)
{
	int	i;
	int	j;

	i = 0;
	while (++i < xy[1])
	{
		j = 0;
		while (++j < xy[0])
		{
			if (map[i][j] > 0)
			{
				map[i][j] = min(map[i - 1][j - 1],
						min(map[i][j - 1], map[i - 1][j])) + 1;
				if (map[i][j] > max)
				{
					max = map[i][j];
					max_index[0] = i - (max - 1);
					max_index[1] = j - (max - 1);
					max_index[2] = i;
					max_index[3] = j;
				}
			}
		}
	}
	return (max_index);
}

void	get_bsq(int **map, char *charset, int *xy)
{
	int	i;
	int	max;
	int	*max_index;

	max_index = (int *)malloc(sizeof(int) * 4);
	max = map[0][0];
	i = 0;
	while (i < 4)
	max_index[i++] = 0;
	get_max_index_first(map, max_index, &max, xy);
	max_index = get_max_index(map, max, max_index, xy);
	print_bsq(map, charset, max_index, xy);
	free(max_index);
}
