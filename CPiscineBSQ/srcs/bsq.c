/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:02:06 by subcho            #+#    #+#             */
/*   Updated: 2022/09/14 00:40:32 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int min(int x, int y)
{
    if (x < y)
        return (x);
    else
        return (y);
}

char	**change_result(int **map, char *charset, int max_index[], int *xy)
{
	char **result;
	int	i;
	int	j;

	i = 0;
	result = (char **)malloc(sizeof(char *) * xy[1] + 1);
	while (i < xy[1])
		result[i++] = (char *)malloc(sizeof(char) * xy[0] + 1);
	result[i] = 0;
	i = 0;
	while (i < xy[0])
	{
		j = 0;
		while (j < xy[1])
		{
			if (map[i][j] == 0)
				result[i][j] = charset[1];
			else if ((i >= max_index[0] && i <= max_index[2]) 
					&& (j >= max_index[1] && j <= max_index[3]))
				result[i][j] = charset[2];
			else
				result[i][j] = charset[0];
			j++;
		}
		result[i][j] = '\0';
		i++;
	}
	return (result);
}

void	print_bsq(char **result, int *xy)
{
	int	i;
	int	j;
	char c;

	i = 0;
	while (i < xy[1])
	{
		j = 0;
		while (j < xy[0])
		{
			c = result[j][i];
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void  get_bsq(int **map, char *charset, int *xy)
{
    int i;
    int j;
    int max;
    int max_index[4];


    max = map[0][0];
    i = 0;
    while (++i < xy[0])
    {    
        j = 0;
       while (++j < xy[1])
        {
           if (map[i][j] > 0)
          {
            map[i][j] += min(map[i - 1][j - 1], min(map[i][j - 1], map[i - 1][j]));
                if (map[i][j] > max)
                   {
                       max = map[i][j];
                       max_index[0] = i - (max - 1);
                       max_index[1] = j - (max - 1);
					   max_index[2] = i;
					   max_index[3] = j;
                    }
           else
             continue ;
            }
        }
	}
	print_bsq(change_result(map, charset, max_index, xy), xy);
}

// int main()
// {
//     int i;
//     int **map;
//     i = 0;
//     map = malloc(sizeof(int *) * 4);
//     while (i < 4)
//         map[i++] = malloc(sizeof(int) * 4);
//     map[0][0] = 0;
//     map[0][1] = 1;
//     map[0][2] = 1;
//     map[0][3] = 1;
//     map[1][0] = 1;
//     map[1][1] = 1;
//     map[1][2] = 1;
//     map[1][3] = 1;
//     map[2][0] = 1;
//     map[2][1] = 1;
//     map[2][2] = 1;
//     map[2][3] = 1;
//     map[3][0] = 0;
//     map[3][1] = 0;
//     map[3][2] = 1;
//     map[3][3] = 0;
	
// 	char charset[3];
// 	charset[0] = '.';
// 	charset[1] = 'o';
// 	charset[2] = 'x';
//     get_bsq(map, charset);
// }
