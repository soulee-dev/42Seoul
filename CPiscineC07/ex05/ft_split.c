/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:52:40 by soulee            #+#    #+#             */
/*   Updated: 2022/09/09 03:03:40 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*get_string(char *str, int start, int len)
{
	int		i;
	char	*result_str;

	result_str = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (str[start + i] != 0 && i < len)
	{
		result_str[i] = str[start + i];
		i++;
	}
	result_str[i] = 0;
	return (result_str);
}

int	is_available_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		while (is_available_in_charset(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && is_available_in_charset(str[i], charset) == 0)
			i++;
	}
	return (count);
}

void	iterate_string(char **result_str, char *str, int *i, char *charset)
{
	int	count_idx;
	int	prev_idx;
	int	j;

	j = 0;
	count_idx = 0;
	prev_idx = 0;
	while (str[*i] != 0)
	{
		if (is_available_in_charset(str[*i], charset))
		{
			if (count_idx > 0)
				result_str[j++] = get_string(str, prev_idx, count_idx);
			count_idx = 0;
			prev_idx = *i + 1;
		}
		else
			count_idx++;
		(*i)++;
	}
	if (count_idx > 0)
		result_str[j++] = get_string(str, prev_idx, count_idx);
	result_str[j] = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		*ptr_i;
	char	**result_str;

	i = 0;
	ptr_i = &i;
	result_str = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	iterate_string(result_str, str, ptr_i, charset);
	return (result_str);
}
