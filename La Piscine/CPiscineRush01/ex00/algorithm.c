/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:54:17 by soulee            #+#    #+#             */
/*   Updated: 2022/09/03 17:38:21 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int arr[4][4] = {
	{4, 3, 2, 1},
	{1, 2, 2, 2},
	{4, 3, 2, 1},
	{1, 2, 2, 2}
	};

	int result [4][4] = {};

	for (int i = 0; i < 4; i++)
	{
		int num = arr[0][i];
		if (num == 1)
			result[0][i] = 4;
		if (num == 2)
		{
			
		}
		if (num == 4)
		{
			for(int j = 0; j < 4; j++)
				result[j][0] = j + 1;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}