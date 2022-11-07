/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:07:47 by soulee            #+#    #+#             */
/*   Updated: 2022/09/15 12:17:43 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*get_string(char *str, int start, int len)
{
	int		i;
	char	*result_str;

	result_str = malloc(sizeof(char) * (len + 1));
	if (!result_str)
		return (NULL);
	i = 0;
	while (str[start + i] != 0 && i < len)
	{
		result_str[i] = str[start + i];
		i++;
	}
	result_str[i] = 0;
	return (result_str);
}

int	**parse_data(t_dict dict, char *file_contents)
{
	int	**map;

	map = create_map(dict);
	if (!parser(0, map, dict, file_contents))
	{
		print_error("map error\n");
		return (0);
	}
	return (map);
}

void	free_map( int **map, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_all(char *file_contents, int *xy, char *charset)
{
	free(file_contents);
	free(xy);
	free(charset);
}

int	check_words(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
