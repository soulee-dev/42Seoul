/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:26:45 by soulee            #+#    #+#             */
/*   Updated: 2022/09/15 12:31:51 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*get_file_contents(char *file_name)
{
	char	*file_contents;
	ssize_t	total_bytes;

	total_bytes = read_file_size(file_name);
	if (!total_bytes)
	{
		print_error("map error\n");
		return (0);
	}
	file_contents = read_file(total_bytes, file_name);
	if (!file_contents)
	{
		print_error("map error\n");
		return (0);
	}
	return (file_contents);
}

int	*get_xy(int rows, int cols)
{
	int		*xy;

	xy = malloc(sizeof(int) * 2);
	xy[0] = rows;
	xy[1] = cols;
	return (xy);
}

int	handle_file(char *file_name)
{
	int		*xy;
	int		**map;
	char	*file_contents;
	t_dict	dict;

	file_contents = get_file_contents(file_name);
	if (!file_contents)
		return (1);
	dict = parse_header(file_contents);
	if (dict.cols < 1 || dict.header_bytes < 4)
	{
		print_error("map error\n");
		return (1);
	}
	map = parse_data(dict, file_contents);
	if (!map)
	{
		free_map(map, dict.cols);
		return (1);
	}
	xy = get_xy(dict.rows, dict.cols);
	get_bsq(map, dict.charset, xy);
	free_all(file_contents, xy, dict.charset);
	free_map(map, dict.cols);
	return (0);
}

int	ft_stdio(void)
{
	char	buf[1024];
	int		fd;
	int		n;

	fd = open("map", O_CREAT | O_WRONLY | O_TRUNC);
	if (!fd)
		return (0);
	n = 1;
	while (n > 0)
	{
		n = read(0, buf, 1024);
		write(fd, buf, n);
	}
	close(fd);
	handle_file("map");
	return (1);
}

int	main(int argc, char *argv[])
{
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			handle_file(argv[i++]);
			if (i + 1 <= argc)
				write(1, "\n", 1);
		}
	}
	else
		ft_stdio();
	return (0);
}
