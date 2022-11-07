/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:15:21 by soulee            #+#    #+#             */
/*   Updated: 2022/09/09 19:20:13 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*result_arr;

	result_arr = malloc(sizeof(int) * length);
	if (!result_arr)
		return (NULL);
	i = 0;
	while (i < length)
	{
		result_arr[i] = f(tab[i]);
		i++;
	}
	return (result_arr);
}
