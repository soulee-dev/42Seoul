/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:10:06 by soulee            #+#    #+#             */
/*   Updated: 2023/01/16 02:40:45 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *error_message)
{
	ft_putstr_fd(error_message, 1);
	exit(1);
}

int	exit_game(t_game *game, char *message)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_putstr_fd(message, 1);
	exit(0);
}

int	count_elements(t_game *game, char element)
{
	int	width;
	int	height;
	int	count;

	count = 0;
	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			if (game->map[height][width] == element)
				count++;
			width++;
		}
		height++;
	}
	return (count);
}

int	find_player_coordinate(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			if (game->map[height][width] == 'P')
			{
				game->player_x = width;
				game->player_y = height;
				return (0);
			}
			width++;
		}
		height++;
	}
	return (0);
}