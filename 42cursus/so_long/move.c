/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:56:24 by soulee            #+#    #+#             */
/*   Updated: 2023/01/16 02:41:08 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_move(t_game *game, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = game->player_x + dx;
	ny = game->player_y + dy;
	if (game->map[ny][nx] == 'E' && game->count_current_collectible == game->count_map_collectible)
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
