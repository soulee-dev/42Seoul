/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 01:57:16 by soulee            #+#    #+#             */
/*   Updated: 2022/08/27 02:07:57 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
	{
		i++;
	}
	printf("%d", i);
	return (s1[i] - s2[i]);
}

int main()
{
	char str1[] = "BlockDMask";
	char str2[] = "Block";
	printf("\n\nstrncmp(%s, %s, -1)\t = %d\n", str1, str2, ft_strncmp(str1, str2, 6));
}