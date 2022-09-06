/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:21:23 by soulee            #+#    #+#             */
/*   Updated: 2022/09/07 00:30:13 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_possible(int x1, int x2, int y1, int y2)
{
	if ((x1 - x2) == (y1 - y2) || (x2 - x1) == (y1 - y2))
		return (0);
	if (y1 == y2)
		return (0);
	return (1);
}

void	print_arr(int arr[], int *ptr_count)
{
	int		i;
	char	c;

	*ptr_count = *ptr_count + 1;
	i = 0;
	while (i < 10)
	{
		c = (char)(arr[i++] + '0');
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

void	dfs(int col, int arr[], int *ptr_count)
{
	int	i;
	int	j;
	int	is_possible;

	if (10 == col)
		print_arr(arr, ptr_count);
	i = -1;
	while (++i < 10)
	{
		is_possible = 1;
		j = -1;
		while (++j < col)
		{
			arr[col] = i;
			if (!check_possible(j, col, arr[j], arr[col]))
			{
				is_possible = 0;
				break ;
			}
		}
		if (is_possible)
			dfs(col + 1, arr, ptr_count);
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	count;
	int	*ptr_count;
	int	arr[11];

	i = 0;
	count = 0;
	ptr_count = &count;
	while (i < 10)
	{
		arr[0] = i;
		dfs(1, arr, ptr_count);
		i++;
	}
	return (count);
}

// int	main(void)
// {
// 	ft_ten_queens_puzzle();
// 	return (0);
// }
