/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 00:32:30 by soulee            #+#    #+#             */
/*   Updated: 2022/09/12 23:22:54 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char	*str)
{
	int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

void	ft_putstr(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

int	**read_dict(int x, int y, char *file_name)
{
	int		i;
	int		**map;
	char	**splitted_file_contents;

	splitted_file_contents = ft_split(read_file(file_name), "\n");
	valid_file(splitted_file_contents);
	i = 0;
	map = (int **)malloc(sizeof(int *) * x);
	while (i < x)
	{
		map[i] = (int *)malloc(sizeof(int) * y);
		i++;
	}
	while (*splitted_file_contents != 0)
	{
		printf("%s\n", *splitted_file_contents);
		splitted_file_contents++;
	}
	return (0);
}

int	count_tab(char **tab)
{
	int	count;

	count = 0;
	while (*tab++ != 0)
		count++;
	return (count);
}
