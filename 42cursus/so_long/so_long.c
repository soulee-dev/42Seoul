/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:47:29 by soulee            #+#    #+#             */
/*   Updated: 2022/12/22 22:12:05 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"
#include "get_next       _line.h"

int	count_char(char *str, char chr)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == chr)
			count++;
		str++;
	}
	return (count);
}

char	**ft_linejoin(char **lines, char *line)
{
	int	i;
	int	count_lines;
	char **new_lines;

	i = 0;
	count_lines = 0;
	while (*lines)
		count_lines++;
	
	new_lines = malloc(sizeof(char *) * count_lines + 1);
	while (lines[i])
		new_lines[i] = lines[i];
	
	return (new_lines);
}

int	valid_map(char *file_name)
{
	// check is ending with .ber
	// check whether is open,
	// is map include E, C, P
	int		fd;
	char	*line;

	if (!ft_strnstr(file_name, ".ber", ft_strlen(file_name)))
		return (0);
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	
	char	**lines;
	
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("INVALID ARGUMENT");
		exit(1);
	}
	if(!valid_map(argv[1]))
	{
		printf("INVALD MAP");
		exit(1);
	}
}