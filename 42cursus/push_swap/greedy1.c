/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:42:06 by soulee            #+#    #+#             */
/*   Updated: 2023/02/21 17:20:40 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_instructions_b(t_stack *stack, int val, int *flag)
{
	int		i;
	t_node	*node;

	i = 0;
	node = stack->b_top;
	while (i < stack->b_size)
	{
		if (node->content == val)
			break ;
		i++;
		node = node->next;
	}
	if (i > stack->b_size / 2)
	{
		*flag = 1;
		return (stack->b_size - i);
	}
	else
	{
		*flag = 0;
		return (i);
	}
}

int	get_mid_index(t_node *node, int val)
{
	int	count;

	count = 0;
	while (node && (node->content > val))
	{
		count++;
		node = node->next;
	}
	while (node && (node->content < val))
	{
		count++;
		node = node->next;
	}
	return (count);
}

int	get_a_max_min(t_stack *stack)
{
	t_node	*node;
	int		max;
	int		i;
	int		max_idx;

	max = -2147483648;
	node = stack->a_top;
	i = 0;
	while (node)
	{
		if (node->content > max)
		{
			max = node->content;
			max_idx = i;
		}
		node = node->next;
		i++;
	}
	if (max_idx == (stack->a_size))
		return (0);
	return (max_idx + 1);
}

int	count_instructions_a(t_stack *stack, int val)
{
	int		count;
	t_node	*node;

	count = 0;
	node = stack->a_top;
	while (node)
	{
		if (node->content < val)
			count++;
		node = node->next;
	}
	if (count == 0 || count == stack->a_size)
		return (get_a_max_min(stack));
	else
		count = (get_mid_index(stack->a_top, val));
	if (count == stack->a_size)
		return (0);
	return (count);
}

void	greedy(t_stack *stack)
{
	int		a;
	int		b;
	int		flag_b;
	int		flag_a;
	int		optimal;

	optimal = get_optimal_instructions(stack, stack->b_top);
	flag_b = 1;
	flag_a = 0;
	a = count_instructions_a(stack, optimal);
	if (a >= stack->a_size / 2)
	{
		flag_a = 1;
		a = stack->a_size - a;
	}
	b = count_instructions_b(stack, optimal, &flag_b);
	apply_rotate_a(stack, a, flag_a);
	apply_rotate_b(stack, b, flag_b);
	pa(stack);
}
