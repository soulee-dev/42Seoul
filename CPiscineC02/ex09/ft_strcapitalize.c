/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:07:06 by soulee            #+#    #+#             */
/*   Updated: 2022/08/30 23:44:25 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	while (str[i] != 0)
	{
		if (str[0] >= 'a' && str[0] <= 'z')
			str[0] -= ('a' - 'A');
		if ((str[i - 1] >= '0' && str[i - 1] <= '9') || (str[i - 1] >= 'A' && str[i - 1] <= 'Z') 
			|| (str[i - 1] >= 'a' && str[i - 1] <= 'z') )
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= ('a' - 'A');
		}
		else
		{
			printf("%c ", str[i]);
		}
		i++;
	}
	return (str);
}

int main()
{
	char str[] = "MuEsq?$(H& UY#XP0GXa0`K@G(V^?=G70>$";
	printf("%s", ft_strcapitalize(str));
	return 1;
}