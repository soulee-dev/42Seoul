/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:58:30 by soulee            #+#    #+#             */
/*   Updated: 2023/01/16 20:39:52 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# define TILE_SIZE 32
# define WINDOW_TITLE "Radioactive Cat"

enum e_keys{
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	X_EVENT_KEY_RELEASE = 3,
	X_EVENT_KEY_EXIT = 17
};

typedef struct s_sprites {
	void	*tile;
	void	*wall;
	void	*barrel;
	void	*player;
	void	*exit;
}	t_sprites;

typedef struct s_game {
	void		*mlx;
	void		*win;
	int			player_x;
	int			player_y;
	int			width;
	int			height;
	char		**map;
	int			count_map_collectible;
	int			count_current_collectible;
	int			count_steps;
	t_sprites	sprites;
}	t_game;

typedef struct s_check {
	int	**map;
	int	count_map_collectible;
	int	is_valid_exit;
}	t_check;

void	load_sprites(t_game *game);
void	draw_map(t_game *game);
void	load_map(char *file_name, t_game *game);
int		render_move(t_game *game, int dx, int dy);
int		exit_game(t_game *game, char *message);
void	exit_error(char *error_message);
int		count_elements(t_game *game, char element);
void	check_valid_map(t_game *game, t_check *check);
int		find_player_coordinate(t_game *game);
void	free_all_map(void **map);
int		check_characters(t_game *game);
#endif