/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:45:40 by soulee            #+#    #+#             */
/*   Updated: 2022/09/15 12:34:06 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*read_file(ssize_t total_bytes, char *file_name)
{
	int		fd;
	char	*file_contents;

	if (total_bytes <= 0)
		return (0);
	file_contents = malloc(sizeof(char) * total_bytes);
	if (!file_contents)
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		free(file_contents);
		return (0);
	}
	read(fd, file_contents, total_bytes);
	close(fd);
	return (file_contents);
}

ssize_t	read_file_size(char *file_name)
{
	int		fd;
	char	buffer[1024];
	ssize_t	read_size;
	ssize_t	total_bytes;

	read_size = 1;
	total_bytes = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (0);
	}
	while (read_size > 0)
	{
		read_size = read(fd, buffer, 1024);
		total_bytes += read_size;
	}
	close(fd);
	return (total_bytes);
}

t_dict	parse_header(char *file_contents)
{
	int		i;
	int		header_bytes;
	char	*cols_data;
	int		line_bytes;
	t_dict	dict;

	i = 0;
	header_bytes = 0;
	while (file_contents[i] && file_contents[i++] != '\n')
		header_bytes++;
	dict.header_bytes = header_bytes;
	cols_data = get_string(file_contents, 0, header_bytes - 3);
	dict.cols = ft_atoi(cols_data);
	dict.charset = get_string(file_contents, header_bytes - 3, 3);
	i = dict.header_bytes + 1;
	line_bytes = 0;
	while (file_contents[i] && file_contents[i++] != '\n')
		line_bytes++;
	dict.rows = line_bytes;
	free(cols_data);
	return (dict);
}

int	**create_map(t_dict dict)
{
	int		i;
	int		**map;

	i = 0;
	map = (int **)malloc(sizeof(int *) * dict.cols);
	if (!map)
		return (0);
	while (i < dict.cols)
	{
		map[i] = (int *)malloc(sizeof(int) * dict.rows);
		if (!map[i++])
			return (0);
	}
	return (map);
}

int	parser(int i, int **map, t_dict dict, char *file_contents)
{
	int	j;
	int	k;

	i = dict.header_bytes;
	j = 0;
	k = 0;
	while (file_contents[++i])
	{
		if (file_contents[i] == '\n')
		{
			if (dict.rows != k)
				return (0);
			j++;
			k = 0;
		}
		else if (file_contents[i] == dict.charset[0] && j < dict.cols)
			map[j][k++] = 1;
		else if (file_contents[i] == dict.charset[1] && j < dict.cols)
			map[j][k++] = 0;
		else
			return (0);
	}
	if (dict.cols != j)
		return (0);
	return (1);
}
