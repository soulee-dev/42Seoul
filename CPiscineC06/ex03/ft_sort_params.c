/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:10:45 by soulee            #+#    #+#             */
/*   Updated: 2022/08/31 18:35:25 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	**sort(char **str_arr, int size)
{
	int		i;
	int		j;
	char	*temp_str;

	i = 0;
	str_arr++;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(str_arr[i], str_arr[j]) > 0)
			{
				temp_str = str_arr[i];
				str_arr[i] = str_arr[j];
				str_arr[j] = temp_str;
			}
			j++;
		}
		i++;
	}
	return (str_arr);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		size;

	i = 0;
	size = argc - 1;
	argv = sort(argv, size);
	while (i < size)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
}
