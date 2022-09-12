/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:07:11 by soulee            #+#    #+#             */
/*   Updated: 2022/09/11 22:45:13 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

int	get_count(int size, char **strs, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
		count += ft_ft_ft_strlen(strs[i++]);
	count = count + ft_ft_ft_strlen(sep) * (size - 1) + 1;
	return (count);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*result;

	if (size == 0)
	{
		result = malloc(sizeof(char));
		*result = 0;
		return (result);
	}
	result = malloc(sizeof(char) * get_count(size, strs, sep));
	if (!result)
		return (NULL);
	*result = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}
