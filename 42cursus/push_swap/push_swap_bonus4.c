/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:50:52 by soulee            #+#    #+#             */
/*   Updated: 2023/02/22 16:25:57 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
			wrap_exit(EXIT_ERROR, "Error");
	}
	if (sign * num > 2147483647 || sign * num < -2147483648)
		wrap_exit(EXIT_ERROR, "Error");
	add_node_back(node, create_new_node(sign * num));
}

t_stack	*parse_arguments(char **argv)
{
	int		i;
	int		j;
	t_node	*list_a;
	char	**splitted_data;

	i = 1;
	list_a = 0;
	while (argv[i])
	{
		j = 0;
		splitted_data = ft_split(argv[i], ' ');
		while (splitted_data[j])
		{
			wrap_atoi(&list_a, splitted_data[j]);
			j++;
		}
		free_split(splitted_data, j);
		splitted_data = 0;
		i++;
	}
	return (init_stack(list_a));
}

t_stack	*init_stack(t_node *list_a)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->a_top = list_a;
	stack->a_bot = get_last_node(list_a);
	stack->a_size = get_list_size(list_a);
	stack->b_top = 0;
	stack->b_bot = 0;
	stack->b_size = 0;
	return (stack);
}
