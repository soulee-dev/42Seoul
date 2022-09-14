/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:03:36 by soulee            #+#    #+#             */
/*   Updated: 2022/09/14 00:24:17 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // REMOVE BEFORE FLIGHT

char	*read_file(char *filename);
void	ft_putstr(int fd, char *str);
void	print_error(char *str);
int		**read_dict(char *file_name);
char	**ft_split(char *str, char *charset);
int		count_tab(char **tab);
void	valid_file(char **splitted_file_contents);
int		ft_strlen(char	*str);
char	*get_string(char *str, int start, int len);
int		ft_atoi(char *str);
int		is_printable(char *str);
int		is_numeric(char *str);
void  get_bsq(int **map, char *charset, int *xy);
char	*read_charset(char **splitted_file_contents);
int 	*get_size(char **splitted_file_contents);
#endif