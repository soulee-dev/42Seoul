/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:09:37 by soulee            #+#    #+#             */
/*   Updated: 2022/11/12 17:50:51 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*result_str;

	if (!s)
		return (NULL);
	result_str = malloc(sizeof(char) * (len));
	if (!result_str)
		return (0);
	if ((unsigned int)(ft_strlen(s)) <= start)
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
