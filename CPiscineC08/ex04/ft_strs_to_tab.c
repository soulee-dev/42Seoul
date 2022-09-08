/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 00:06:59 by soulee            #+#    #+#             */
/*   Updated: 2022/09/09 03:06:48 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

char	*ft_strdup(char *str, int size)
{
	char	*str_dup;
	int		i;

	i = 0;
	str_dup = malloc(sizeof(char) * (size + 1));
	if (!str_dup)
		return (NULL);
	while (str[i] != '\0')
	{
		str_dup[i] = str[i];
		i++;
	}
	str_dup[i] = 0;
	return (str_dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stock_list;

	stock_list = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock_list)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stock_list[i].size = ft_strlen(av[i]);
		stock_list[i].str = av[i];
		stock_list[i].copy = ft_strdup(stock_list[i].str, stock_list[i].size);
		i++;
	}
	stock_list[i].size = 0;
	stock_list[i].str = 0;
	stock_list[i].copy = 0;
	return (stock_list);
}
