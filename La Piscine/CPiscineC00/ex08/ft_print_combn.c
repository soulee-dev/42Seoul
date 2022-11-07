/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:34:02 by soulee            #+#    #+#             */
/*   Updated: 2022/08/28 15:45:34 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	dfs(int n, int depth, int s, char arr[])
{
	int	i;

	i = s + 1;
	if (n == depth)
	{
		write(1, arr, n);
		if (arr[0] == 10 - n + '0')
			return ;
		write(1, ", ", 2);
		return ;
	}
	while (i < 10)
	{
		arr[depth] = i + '0';
		dfs(n, depth + 1, i, arr);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	dfs(n, 0, -1, arr);
}
