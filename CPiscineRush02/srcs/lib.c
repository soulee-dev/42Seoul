/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 00:32:30 by soulee            #+#    #+#             */
/*   Updated: 2022/09/11 16:28:37 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

char	*read_file(char *filename)
{
	int		fd;
	char	buffer[1024];
	char	*file_contents;
	ssize_t	read_size;
	ssize_t	total_size;

	read_size = 1;
	total_size = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(2, "File is not valid");
		return (NULL);
	}
	while (read_size > 0)
	{
		read_size = read(fd, buffer, 1024);
		total_size += read_size;
	}
	close(fd);
	if (read_file < 0)
	{
		ft_putstr(2, "File is not valid (size)");
		return (NULL);
	}
	file_contents = malloc(sizeof(char) * total_size);
	fd = open(filename, O_RDONLY);
	read(fd, file_contents, total_size);
	close(fd);
	return (file_contents);
}
