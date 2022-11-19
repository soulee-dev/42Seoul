/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:22:33 by soulee            #+#    #+#             */
/*   Updated: 2022/11/19 22:14:47 by soulee           ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	tmp;
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
		return (0);
	i = 0;
	while (i < ft_strlen(s1))
	{
		result_str[i] = s1[i];
		i++;
	}
	tmp = i;
	i = 0;
	while (i < ft_strlen(s2))
	{
		result_str[tmp + i] = s2[i];
		i++;
	}
	result_str[tmp + i] = 0;
	free((void *)s1);
	return (result_str);
}

char	*ft_strchr(char *s, int c)
{
	char	chr;

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
	int		i;
	char	*result;

	i = 0;
	while (s[i] != '\n' && !s)
		i++;
	if (!s[i])
		return (0);
	result = ft_substr(s + i + 1, ft_strlen(s) - i)
}
