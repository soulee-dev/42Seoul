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
	char			buffer[BUFFER_SIZE];
	static char		*text_buffer[OPEN_MAX];

	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size < 0 || BUFFER_SIZE < 1)
		return (NULL);

	while (read_size > 0)
	{
		buffer[read_size] = NULL;
		text_buffer[fd] = ft_strjoin(text_buffer[fd], buffer);
		if (ft_strchr(text_buffer[fd], '\n'))
			return (ft_extract_line(text_buffer[fd]));
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	// return (ft_extract_line(text_buffer[fd]));
	return (NULL);
}

int	main()
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (line = get_next_line(fd))
	{
		// printf("%s", line);
	}
}