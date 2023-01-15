/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:22:41 by soulee            #+#    #+#             */
/*   Updated: 2023/01/16 03:44:56 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_game(game, "Exited");
	if (key_code == KEY_W)
		render_move(game, 0, -1);
	if (key_code == KEY_S)
		render_move(game, 0, 1);
	if (key_code == KEY_A)
		render_move(game, -1, 0);
	if (key_code == KEY_D)
		render_move(game, 1, 0);
	return (0);
}

void	init_params(t_game *game, t_check *check)
{
	game->count_current_collectible = 0;
	game->count_steps = 0;
	check->is_valid_exit = 0;
	find_player_coordinate(game);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	t_check	check;

	if (argc != 2)
		exit_error("INVALID ARGUMENT");
	load_map(argv[1], &game);
	init_params(&game, &check);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * TILE_SIZE,
			game.height * TILE_SIZE, WINDOW_TITLE);
	load_sprites(&game);
	check_valid_map(&game, &check);
	draw_map(&game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_hook, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
