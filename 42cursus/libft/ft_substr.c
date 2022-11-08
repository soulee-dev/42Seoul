/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:09:37 by soulee            #+#    #+#             */
/*   Updated: 2022/11/08 20:43:49 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*result_str;

	result_str = malloc(sizeof(char) * (len + 1));
	if (!result_str)
		return (0);
	if ((unsigned int)(ft_strlen((char *)s)) <= start)
	{
		result_str[0] = 0;
		return (result_str);
	}
	if (!result_str)
		return (NULL);
	i = 0;
	while (s[start + i] != 0 && i < len)
	{
		result_str[i] = s[start + i];
		i++;
	}
	result_str[i] = 0;
	return (result_str);
}
