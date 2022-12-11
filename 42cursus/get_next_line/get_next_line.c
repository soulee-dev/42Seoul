/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:10:12 by soulee            #+#    #+#             */
/*   Updated: 2022/12/11 23:19:28 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	if (!s)
		return (0);
	chr = (char)c;
	while (*s)
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (*s == chr)
		return ((char *)s);
	return (0);
}

char	*ft_extract_line(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	return (ft_strndup(s, i + 1));
}

void	ft_mem_clear(char **mem)
{
	free(*mem);
	*mem = 0; 
}

char	*get_next_line(int fd)
{
	char		*line;
	ssize_t		read_size;
	static char	*text_buffer[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];

	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size < 0)
	{
		ft_mem_clear(&text_buffer[fd]);
		return (NULL);
	}
	while (read_size > 0)
	{
		buffer[read_size] = 0;
		text_buffer[fd] = ft_strjoin(text_buffer[fd], buffer);
		if (ft_strchr(text_buffer[fd], '\n'))
			break ;
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	if (!text_buffer[fd])
		return (NULL);
	line = ft_extract_line(text_buffer[fd]);
	text_buffer[fd] = ft_remain_text(text_buffer[fd]);
	return (line);
}
