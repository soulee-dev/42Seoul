/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:56:24 by soulee            #+#    #+#             */
/*   Updated: 2023/01/16 20:25:08 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_move(t_game *game, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = game->player_x + dx;
	ny = game->player_y + dy;
	if (game->map[ny][nx] == 'E' && game->count_current_collectible
		== game->count_map_collectible)
		exit_game(game, "Completed!");
	if (game->map[ny][nx] == 'C')
		game->count_current_collectible++;
	if (game->map[ny][nx] == '1' || game->map[ny][nx] == 'E')
		return (1);
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = nx;
	game->player_y = ny;
	game->map[ny][nx] = 'P';
	game->count_steps++;
	ft_putnbr_fd(game->count_steps, 1);
	ft_putstr_fd("\n", 1);
	draw_map(game);
	return (0);
}

int	check_characters(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			if (game->map[height][width] != '1' &&
				game->map[height][width] != '0' &&
				game->map[height][width] != 'C' &&
				game->map[height][width] != 'E' &&
				game->map[height][width] != 'P')
				return (0);
			width++;
		}
		height++;
	}
	return (1);
}
