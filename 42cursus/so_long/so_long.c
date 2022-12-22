/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:47:29 by soulee            #+#    #+#             */
/*   Updated: 2022/12/19 20:26:05 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"

int	valid_map(char *file_name)
{
	// check is ending with .ber
	// check whether is open,
	// is map include E, C, P
	int		fd;
	char	buffer[1024];
	ssize_t	read_size;

	if (!ft_strnstr(file_name, ".ber", ft_strlen(file_name)))
		return (0);
	fd = open(file_name, O_RDONLY);
	read_size = read(fd, buffer, 1024);
	if (read_size < 0)
		return (0);
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