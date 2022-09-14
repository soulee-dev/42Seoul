/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:43:09 by soulee            #+#    #+#             */
/*   Updated: 2022/09/13 21:50:05 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	count_tab(char **tab)
{
	int	count;

	count = 0;
	while (*tab++ != 0)
		count++;
	return (count);
}

int	ft_strlen(char	*str)
{
	int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

void	ft_putstr(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}