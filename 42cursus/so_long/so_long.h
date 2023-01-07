/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:58:30 by soulee            #+#    #+#             */
/*   Updated: 2022/12/31 02:54:28 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# define TILE_SIZE 32

enum e_keys{
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2
};

typedef struct s_sprites {
	void	*tile;
}	t_sprites;

typedef struct s_game {
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			width;
	int			height;
	char		**map;
	t_sprites	sprites;
}	t_game;


void	load_sprites(t_game *game);
void	draw_map(t_game *game);
void	load_map(char *file_name);
#endif