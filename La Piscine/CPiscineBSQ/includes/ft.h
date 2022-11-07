/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:03:36 by soulee            #+#    #+#             */
/*   Updated: 2022/09/15 12:25:01 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_dict
{
	int		rows;
	int		cols;
	int		header_bytes;
	char	*charset;
}	t_dict;

ssize_t	read_file_size(char *file_name);
char	*read_file(ssize_t total_bytes, char *file_name);
t_dict	parse_header(char	*file_contents);
char	*get_string(char *str, int start, int len);
int		ft_atoi(char *str);
int		**create_map(t_dict dict);
int		parser(int i, int **map, t_dict dict, char *file_contents);
int		**parse_data(t_dict dict, char *file_contents);
void	print_error(char *msg);
void	get_bsq(int **map, char *charset, int *xy);
void	free_all(char *file_contents, int *xy, char *charset);
void	free_map( int **map, int cols);
int		check_words(char *str);
#endif