/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:53:12 by soulee            #+#    #+#             */
/*   Updated: 2022/09/09 03:11:31 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*ptr;

	ptr = dest;
	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = 0;
	return (ptr);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++ != '\0')
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*str_ptr;

	str_ptr = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!str_ptr)
		return (NULL);
	ft_strcpy(str_ptr, src);
	return (str_ptr);
}
