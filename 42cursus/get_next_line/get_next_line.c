/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:22:35 by soulee            #+#    #+#             */
/*   Updated: 2022/11/10 03:22:47 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char		*text_buffer[OPEN_MAX];
    ssize_t			read_size;
    char			buffer[BUFFER_SIZE];

	read_size = read(fd, buffer, BUFFER_SIZE);
    while (read_size > 0 && !ft_strchr(text_buffer, '\n'))
    {
        text_buffer[fd] = ft_strjoin(text_buffer[fd], buffer);
        read_size = read(fd, buffer, BUFFER_SIZE);
    }

    printf("%s", text_buffer);
}

int main()
{
    
}
