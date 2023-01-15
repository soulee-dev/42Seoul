/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 04:27:02 by soulee            #+#    #+#             */
/*   Updated: 2023/01/16 03:44:38 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	_ft_strlen(const char *s)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (*s++)
		count++;
	return (count);
}

void	load_map(char *file_name, t_game *game)
{
	int	height;
	int	fd;
	char	*line;
	static	char	*map;

	height = 0;
	map = 0;
	if (_ft_strlen(ft_strnstr(file_name, ".ber", ft_strlen(file_name))) != 4)
		exit_error("INVALID MAP (EXTENSION)");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit_error("INVALID MAP (FILE)");
	line = get_next_line(fd);

	while (line)
	{
		map = ft_strjoin(map, line);
		line = get_next_line(fd);
		height++;
	}
	game->map = ft_split(map, '\n');
	game->height = height;
	game->width = ft_strlen(game->map[0]);
}

void	load_sprites(t_game *game)
{
	int	width;
	int	height;

	game->sprites.tile = mlx_xpm_file_to_image(
			game->mlx, "./sprites/tile.xpm", &width, &height);
	game->sprites.wall = mlx_xpm_file_to_image(
			game->mlx, "./sprites/wall.xpm", &width, &height);
	game->sprites.barrel = mlx_xpm_file_to_image(
			game->mlx, "./sprites/barrel.xpm", &width, &height);
	game->sprites.player = mlx_xpm_file_to_image(
			game->mlx, "./sprites/player.xpm", &width, &height);
	game->sprites.exit = mlx_xpm_file_to_image(
			game->mlx, "./sprites/exit.xpm", &width, &height);
}

void	draw_map(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(
					game->mlx, game->win, game->sprites.tile,
					width * TILE_SIZE, height * TILE_SIZE);
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(
					game->mlx, game->win, game->sprites.wall,
					width * TILE_SIZE, height * TILE_SIZE);
			if (game->map[height][width] == 'C')
				mlx_put_image_to_window(
					game->mlx, game->win, game->sprites.barrel,
					width * TILE_SIZE, height * TILE_SIZE);
			if (game->map[height][width] == 'P')
				mlx_put_image_to_window(
					game->mlx, game->win, game->sprites.player,
					width * TILE_SIZE, height * TILE_SIZE);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(
					game->mlx, game->win, game->sprites.exit,
					width * TILE_SIZE, height * TILE_SIZE);
			width++;
		}
		height++;
	}
	mlx_string_put(game->mlx, game->win, 5, 5, 0, ft_itoa(game->count_steps));
}
