/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:43:58 by soulee            #+#    #+#             */
/*   Updated: 2022/08/24 22:26:48 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	mid;

	mid = size / 2;
	while (mid != 0)
	{
		tmp = tab[mid - 1];
		tab[mid - 1] = tab[size - mid];
		tab[size - mid] = tmp;
		mid--;
	}
}
