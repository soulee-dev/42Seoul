/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:45:40 by soulee            #+#    #+#             */
/*   Updated: 2022/09/12 23:18:02 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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
		print_error("ERROR: FILE IO (NOT VALID)\n");
	while (read_size > 0)
	{
		read_size = read(fd, buffer, 1024);
		total_size += read_size;
	}
	close(fd);
	if (total_size <= 0)
		print_error("ERROR: FILE IO (SIZE)\n");
	file_contents = malloc(sizeof(char) * total_size);
	fd = open(filename, O_RDONLY);
	read(fd, file_contents, total_size);
	close(fd);
	return (file_contents);
}
