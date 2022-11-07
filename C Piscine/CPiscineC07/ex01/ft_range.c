/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:10:47 by soulee            #+#    #+#             */
/*   Updated: 2022/09/01 15:55:12 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (min >= max)
		return (NULL);
	i = 0;
	range = (int *)malloc(sizeof(int) * (max - min));
	if (!range)
		return (NULL);
	while (i < max - min)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
