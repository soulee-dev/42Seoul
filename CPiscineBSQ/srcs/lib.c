/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 00:32:30 by soulee            #+#    #+#             */
/*   Updated: 2022/09/13 00:25:48 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char	*str)
{
	int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

void	ft_putstr(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

int	**create_map(int x, int y, char **splitted_file_contents)
{
	int		i;
	int		j;
	int		**map;
	int		count_first_line;

	count_first_line = ft_strlen(splitted_file_contents[0]);
	i = 0;
	map = (int **)malloc(sizeof(int *) * x);
	while (i < x)
	{
		map[i] = (int *)malloc(sizeof(int) * y);
		i++;
	}
	i = 0;
	while (i < x)
	{
		j = 1;
		while (j <= y)
		{
			map[i][j - 1] = splitted_file_contents[j][i];
			printf("%c ", splitted_file_contents[j][i]);
			j++;
		}
		i++;
	}
	free(splitted_file_contents);
	return (map);
}

int	**read_dict(char *file_name)
{
	int		lines;
	int		**map;
	int		count_first_line;
	char	**splitted_file_contents;

	splitted_file_contents = ft_split(read_file(file_name), "\n");
	count_first_line = ft_strlen(splitted_file_contents[1]);
	lines = ft_atoi(get_string(splitted_file_contents[0],
				0, count_first_line - 3));
	valid_file(splitted_file_contents);
	map = create_map(count_first_line, lines, splitted_file_contents);
	return (map);
}

int	count_tab(char **tab)
{
	int	count;

	count = 0;
	while (*tab++ != 0)
		count++;
	return (count);
}
