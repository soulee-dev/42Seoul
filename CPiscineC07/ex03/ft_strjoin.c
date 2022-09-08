/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:07:11 by soulee            #+#    #+#             */
/*   Updated: 2022/09/09 03:14:42 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ft_ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	length_dest;
	int	length_src;

	i = 0;
	length_dest = ft_ft_ft_strlen(dest);
	length_src = ft_ft_ft_strlen(src);
	while (i < length_src)
	{
		dest[length_dest + i] = src[i];
		i++;
	}
	dest[length_dest + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*result;
	int		size_of_str;
	int		end_size;
	int		j;

	i = 0;
	j = 0;
	size_of_str = 0;
	end_size = 0;
	result = malloc(sizeof(char) * size);
	*result = '\0';
	if (!result)
		return (NULL);
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i != size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}
