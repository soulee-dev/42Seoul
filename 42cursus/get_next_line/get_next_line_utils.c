/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:22:33 by soulee            #+#    #+#             */
/*   Updated: 2022/11/22 00:24:54 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	temp;

	i = 0;
	temp = ft_strlen(src);
	while (i < temp && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = 0;
	return (temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result_str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strndup(s2, ft_strlen(s2)));
	if (!s2)
		return (ft_strndup(s1, ft_strlen(s1)));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result_str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result_str)
		return (NULL);
	ft_strlcpy(result_str, s1, s1_len + 1);
	free((void *)s1);
	ft_strlcpy(result_str + s1_len, (char *)s2, s2_len + 1);
	return (result_str);
}

char	*ft_strchr(char *s, int c)
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

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*result_str;

	i = 0;
	result_str = malloc(sizeof(char) * (n + 1));
	if (!result_str)
		return (NULL);
	while (i < n)
	{
		result_str[i] = s1[i];
		i++;
	}
	result_str[i] = 0;
	return (result_str);
}

char	*ft_extract_line(char *s)		
{
	int	i;
	char	*line;
	
	i = 0;
	if (s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	// diff
	line = (char *) malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (s[++i] && s[i] != '\n')
		line[i] = s[i];
	if (s[i] == '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = 0;
	return (line);
	// char	*strchr;

	// if (!s)
	// 	return (NULL);
	// strchr = ft_strchr(s, '\n');
	// if (!strchr)
	// 	return (strchr);
	// return (ft_strndup(s, strchr - s + 1));

	// while 문을 \n 나 \0이 닿을때까지 돌려
	// \\ 이거를 strlcpy 해주는거야
	// i'm fuking genius
}

char	*ft_remove_line(char *s)
{
	int	i;
	int	j;
	char	*result_str;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	result_str = (char *)malloc(sizeof(*result_str) * ft_strlen(s) - i + 1);
	if (!result_str)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		result_str[j++] = s[i++];
	result_str[j] = 0;
	free(s);
	return (result_str); 
}