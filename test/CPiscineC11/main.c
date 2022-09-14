/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:14:32 by soulee            #+#    #+#             */
/*   Updated: 2022/09/13 21:14:33 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 3);
	tab[0] = malloc(sizeof(char) * 4);
	tab[1] = malloc(sizeof(char) * 4);
	tab[2] = malloc(sizeof(char) * 4);

	tab[2] = "abc";
	tab[1] = "def";
	tab[0] = "hig";

	int	i;

	i = 0;
	
	while (i < 3)
	{
		printf("%s\n", tab[i]);
		i++;
	}

	ft_advanced_sort_string_tab(tab, ft_strcmp);

	i = 0;
	while (i < 3)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}