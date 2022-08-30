/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:14:57 by soulee            #+#    #+#             */
/*   Updated: 2022/08/30 23:01:36 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*ptr_str;
	char	*ptr_to_find;

	if (!*to_find)
		return (str);
	while (*str != '\0')
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
