/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:10:12 by soulee            #+#    #+#             */
/*   Updated: 2022/12/11 16:19:40 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	ssize_t		read_size;
	static char	*text_buffer[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];

	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size < 0)
	{
		if (text_buffer[fd])
		{
			free(text_buffer[fd]);
			text_buffer[fd] = 0;
		}
		return (NULL);
	}
	buffer[read_size] = 0;
	while (read_size > 0)
	{
		text_buffer[fd] = ft_strjoin(text_buffer[fd], buffer);
		read_size = read(fd, buffer, BUFFER_SIZE);
		buffer[read_size] = 0;
	}
	if (!text_buffer[fd])
		return (NULL);
	line = ft_extract_line(text_buffer[fd]);
	text_buffer[fd] = ft_remain_text(text_buffer[fd]);
	return (line);
}

// // REMOVE BEFORE FLIGHT
// int	main() {
// 	int	fd;
// 	char *line;
// 	fd = open("./test.txt", O_RDONLY);

// 	while ((line = get_next_line(fd))) {
// 		printf("start:%s:end\n", line);
// 	}
// 	return (0);
// }
// // REMOVE BEFORE FLIGHT