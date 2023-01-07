/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:22:41 by soulee            #+#    #+#             */
/*   Updated: 2022/12/31 03:12:01 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	key_hook(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_game(game);
	if (key_code == KEY_W)
		game->y++;
	if (key_code == KEY_S)
		game->y--;
	if (key_code == KEY_A)
		game->x--;
	if (key_code == KEY_D)
		game->x++;
	return (0);
}

void	init_game(t_game *game)
{
	game->x = 0;
	game->y = 0;
	game->width = 20;
	game->height = 20;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("INVALID ARGUMENT", 1);
		exit(1);
	}
	load_map(argv[1]);
	init_game(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * TILE_SIZE,
			game.height * TILE_SIZE, "Hello world!");
	load_sprites(&game);
	draw_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
