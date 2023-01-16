/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:10:06 by soulee            #+#    #+#             */
/*   Updated: 2023/01/16 20:38:51 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *error_message)
{
	ft_putendl_fd(error_message, 2);
	exit(1);
}

int	exit_game(t_game *game, char *message)
{
	mlx_destroy_image(game->mlx, game->sprites.tile);
	mlx_destroy_image(game->mlx, game->sprites.wall);
	mlx_destroy_image(game->mlx, game->sprites.barrel);
	mlx_destroy_image(game->mlx, game->sprites.player);
	mlx_destroy_image(game->mlx, game->sprites.exit);
	mlx_destroy_window(game->mlx, game->win);
	ft_putendl_fd(message, 2);
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

void	free_all_map(void **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = 0;
		i++;
	}
	free(map);
	map = 0;
}
