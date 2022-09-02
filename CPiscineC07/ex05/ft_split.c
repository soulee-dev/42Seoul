/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:52:40 by soulee            #+#    #+#             */
/*   Updated: 2022/09/01 20:53:58 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_ft_ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i != n)
		return (s1[i] - s2[i]);
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		length_str;
	int		length_charset;
	char	temp_str[257];
	int		j;

	i = 0;
	length_str = ft_ft_ft_strlen(str);
	length_charset = ft_ft_ft_strlen(charset);
	result_str = str;

	while (i < length_str)
	{
		if (ft_strncmp(str, charset, length_charset) == 0)
		{
			printf("%d", i);
		}
		str++;
		i++;
	}

	i = 0;
	j = 0;
	while (i < length_str)
	{
		if (str[i] == 0)
		{
			i = 
		}
		temp_str[j++] = 
	}
	
}



void	main()
{
	char	input[] = "aa,bb";
	ft_split(input, ",");
}