/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:22:35 by soulee            #+#    #+#             */
/*   Updated: 2022/11/19 21:53:09 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t			read_size;
	char			buffer[BUFFER_SIZE + 1];
	static char		*text_buffer[OPEN_MAX];
	char			*line;

	read_size = read(fd, buffer, 0);
	if (read_size == -1 || BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	read_size = read(fd, buffer, BUFFER_SIZE);
	while (read_size > 0)
	{
		buffer[read_size] = 0;
		text_buffer[fd] = ft_strjoin(text_buffer[fd], buffer);
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	line = ft_extract_line(text_buffer[fd]);
	text_buffer[fd] = ft_remove_line(text_buffer[fd]);
	return (line);
}

int main() {
	int	fd;
	char	*line;

	fd = open("./test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
}
