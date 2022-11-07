/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:41:47 by soulee            #+#    #+#             */
/*   Updated: 2022/11/07 19:42:59 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	char	*ptr_str;
	char	*ptr_to_find;
	int		i;

	i = 0;
	if (!*to_find)
		return (str);
	while (i < n && *str != '\0')
	{
		if (*str == *to_find)
		{
			ptr_str = str + 1;
			ptr_to_find = to_find + 1;
			while (*ptr_str != '\0' && *ptr_to_find != '\0'
				&& *ptr_str == *ptr_to_find)
			{
				ptr_str++;
				ptr_to_find++;
			}
			if (*ptr_to_find == '\0')
				return (str);
			if (*str == '\0')
				break ;
		}
		str++;
	}
	return ("\0");
}
