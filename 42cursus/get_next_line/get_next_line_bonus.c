#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

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

char	*ft_mem_clear(void *mem)
{
	free(mem);
	return (0);
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
		text_buffer[fd] = ft_mem_clear(text_buffer[fd]);
		return (NULL);
	}
	buffer[read_size] = 0;
	while (read_size > 0)
	{
		text_buffer[fd] = ft_strjoin(text_buffer[fd], buffer);
		if (ft_strchr(text_buffer[fd], '\n'))
			break ;
		read_size = read(fd, buffer, BUFFER_SIZE);
		buffer[read_size] = 0;
	}
	if (!text_buffer[fd])
		return (NULL);
	line = ft_extract_line(text_buffer[fd]);
	text_buffer[fd] = ft_remain_text(text_buffer[fd]);
	return (line);
}
