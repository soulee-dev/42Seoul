/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:50:32 by soulee            #+#    #+#             */
/*   Updated: 2023/02/21 21:51:14 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_node	*create_new_node(int content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	get_list_size(t_node *node)
{
	int	count;

	count = 0;
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}

t_node	*get_last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

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