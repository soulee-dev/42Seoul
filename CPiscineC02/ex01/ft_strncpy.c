/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:18:30 by soulee            #+#    #+#             */
/*   Updated: 2022/08/25 00:45:55 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	count;
	int	i;

	count = 0;
	while (*dest != '0')
	{
		count++;
	}
	i = 0;
	while (i < count)
	{
		dest[i] = src[i];
		i++;
	}
	i = 0;
	while(i < n - count)
	{
		dest[count - 1 - i] = 'z';
		i++;
	}
}

void main()
{
	char a[4];
	char *b = "123";

	ft_strncpy(a, b, 6);

	for(int i = 0; i < 4; i++)
	{
		printf("%s");
	}
	
}