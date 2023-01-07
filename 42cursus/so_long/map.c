/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 04:27:02 by soulee            #+#    #+#             */
/*   Updated: 2023/01/07 17:27:34 by soulee           ###   ########.fr       */
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

void	exit_error(char *error_message)
{
	ft_putstr_fd(error_message, 1);
	exit(1);
}

void	load_map(char *file_name)
{
	int	fd;
	char	*line;
	static	char	*map;

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
	}
	printf("%s", map);
	printf("\n");

}

void	load_sprites(t_game *game)
{
	int	width;
	int	height;

	game->sprites.tile = mlx_xpm_file_to_image(
			game->mlx, "./sprites/tile.xpm", &width, &height);
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
			mlx_put_image_to_window(
				game->mlx, game->win, game->sprites.tile,
				width * TILE_SIZE, height * TILE_SIZE);
			width++;
		}
		height++;
	}
}

// void	dfs(t_game *game, t_check *check, int x, int y)
// {
// 	const int	dx[4] = {0, 0, -1, 1};
// 	const int	dy[4] = {-1, 1, 0, 0};
// 	int			nx;
// 	int			ny;
// 	int			i;

// 	check->visited[y][x] = 1;
// 	i = -1;
// 	if (game->map[y][x] == 'C')
// 		check->item_cnt -= 1;
// 	if (game->map[y][x] == 'E')
// 	{
// 		game->valid_path = 1;
// 		return ;
// 	}
// 	while (++i < 4)
// 	{
// 		nx = x + dx[i];
// 		ny = y + dy[i];
// 		if (game->map[ny][nx] != '1' && !check->visited[ny][nx])
// 			dfs(game, check, nx, ny);
// 	}
// }