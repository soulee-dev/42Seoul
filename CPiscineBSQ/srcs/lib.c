/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 00:32:30 by soulee            #+#    #+#             */
/*   Updated: 2022/09/14 01:19:15 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*read_charset(char **splitted_file_contents)
{
	char	*charset;
	int		count_first_line;

	count_first_line = ft_strlen(splitted_file_contents[0]);
	charset = (char *)malloc(sizeof(int) * 3);
	charset = get_string(splitted_file_contents[0], count_first_line - 3, 3);
	return (charset);
}

int	**create_map(int x, int y, char **splitted_file_contents)
{
	int		i;
	int		j;
	int		**map;
	int		count_first_line;
	char	*charset;

	charset = read_charset(splitted_file_contents);
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
			if (charset[0] == splitted_file_contents[j][i])
				map[i][j - 1] = 1;
			else if (charset[1] == splitted_file_contents[j][i])
				map[i][j - 1] = 0;
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
				0, ft_strlen(splitted_file_contents[0]) - 3));
	valid_file(splitted_file_contents);
	map = create_map(count_first_line, lines, splitted_file_contents);
	return (map);
}

int	*get_size(char **splitted_file_contents)
{
	int	*xy;
	
	xy = malloc(sizeof(int) * 2);
	int		lines;
	int		count_first_line;
	count_first_line = ft_strlen(splitted_file_contents[1]);
	lines = ft_atoi(get_string(splitted_file_contents[0],
				0, ft_strlen(splitted_file_contents[0]) - 3));

	printf("x: %d, y: %d", count_first_line, lines);
	xy[0] = count_first_line;
	xy[1] = lines;

	return (xy);
}