/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 02:52:29 by soulee            #+#    #+#             */
/*   Updated: 2023/01/16 05:26:00 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**create_check_map(t_game *game)
{
	int	**map;
	int	width;
	int	height;

	map = (int **)malloc(sizeof(int *) * game->height);
	if (!map)
		return (0);
	height = 0;
	while (height < game->height)
	{
		map[height] = (int *)malloc(sizeof(int) * (game->width + 1));
		if (!map[height])
		{
			free_all_map((void **)map);
			return (0);
		}
		width = 0;
		while (width < game->width)
		{
			map[height][width] = 0;
			width++;
		}
		height++;
	}
	return (map);
}

void	dfs(t_game *game, t_check *check, int x, int y)
{
	int			i;
	int			nx;
	int			ny;
	const int	dx[4] = {0, 0, 1, -1};
	const int	dy[4] = {1, -1, 0, 0};

	check->map[y][x] = 1;
	if (game->map[y][x] == 'C')
		check->count_map_collectible -= 1;
	if (game->map[y][x] == 'E')
	{
		check->is_valid_exit = 1;
		return ;
	}
	i = 0;
	while (i < 4)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (game->map[ny][nx] != '1' && !check->map[ny][nx])
			dfs(game, check, nx, ny);
		i++;
	}
}

int	check_rectangular(t_game *game)
{
	int	height;

	height = 0;
	while (height < game->height)
	{
		if ((int)ft_strlen(game->map[height]) != game->width)
			return (0);
		height++;
	}
	return (1);
}

int	check_surrouned(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			if (height == 0 || height == game->height - 1)
			{
				if (game->map[height][width] != '1')
					return (0);
			}
			else
			{
				if (game->map[height][0] != '1'
					|| game->map[height][game->width - 1] != '1')
					return (0);
			}
			width++;
		}
		height++;
	}
	return (1);
}

void	check_valid_map(t_game *game, t_check *check)
{
	game->count_map_collectible = count_elements(game, 'C');
	if (game->count_map_collectible <= 0)
		exit_game(game, "INVALID MAP (NO COLLECTIBLE)");
	if (count_elements(game, 'P') != 1)
		exit_game(game, "INVALID MAP (NO PLAYER)");
	if (count_elements(game, 'E') != 1)
		exit_game(game, "INVALID MAP (NO EXIT)");
	if (!check_rectangular(game))
		exit_game(game, "INVALID MAP (NOT RECTENGULAR)");
	if (!check_surrouned(game))
		exit_game(game, "INVALID MAP (NOT SURROUNDED)");
	check->count_map_collectible = game->count_map_collectible;
	check->map = create_check_map(game);
	dfs(game, check, game->player_x, game->player_y);
	if (!check->is_valid_exit || check->count_map_collectible != 0)
		exit_game(game, "INVALID MAP (NO PATH)");
}
