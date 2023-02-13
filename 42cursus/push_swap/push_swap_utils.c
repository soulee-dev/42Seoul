/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:37:30 by soulee            #+#    #+#             */
/*   Updated: 2023/02/13 16:46:17 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	wrap_atoi(t_node **node, const char *str)
{
	long long	num;
	long long	sign;

	num = 0;
	sign = 1;
	while (((int)(*str) >= 9 && (int)(*str) <= 13) || (int)(*str) == 32)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			num = num * 10 + (*str - '0');
			str++;
		}
		else
			wrap_exit(EXIT_ERROR, "INVALID ARGUMENT (NON INTEGER)");
	}
	if (sign * num > 2147483647 || sign * num < -2147483648)
		wrap_exit(EXIT_ERROR, "INVALID ARGUMENT (EXCEED INTEGER)");
	add_node_back(node, create_new_node(sign * num));
}
