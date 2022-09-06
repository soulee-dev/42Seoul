/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:33:21 by soulee            #+#    #+#             */
/*   Updated: 2022/09/03 17:38:13 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

int	count_skyscrapper(int numbers[], int size)
{
	int	max;
	int	i;
	int	count;

	i = 0;
	max = -1;
	while (i < size)
	{
		if (numbers[i] > max)
		{
			max = numbers[i];
			count += 1;
		}
		i++;
	}
	return (count);
}

int	**argv_parser(char *str, int size)
{
	int	i;
	int	j;
	int	**arr;

	i = -1;
	j = 0;
	arr = (int **)malloc(sizeof(int *) * size);
	while (++i < size)
		arr[i] = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			if (j == size)
			{
				i += 1;
				j = 0;
			}
			arr[i][j] = (*str - '0');
			j += 1;
		}
		str++;
	}
	return (arr);
}

int	main(int argc, char *argv[])
{
	int	**numbers;

	if (argc != 2)
	{
		ft_putstr(2, "INVALID_ARGUMENT");
		return (1);
	}
	numbers = argv_parser(argv[1], 4);
}
