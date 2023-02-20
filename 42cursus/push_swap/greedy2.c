/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:29:43 by soulee            #+#    #+#             */
/*   Updated: 2023/02/20 17:42:23 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_rotate_a(t_stack *stack, int a)
{
	while (a)
	{
		if (flag)
			rra(stack);
		else
			ra(stack);
		a--;
	}
}

void	apply_rotate_b(t_stack *stack, int b, int flag)
{
	while (b)
	{
		if (flag)
			rrb(stack);
		else
			rb(stack);
		b--;
	}
}

void	apply_rotate_last(t_stack *stack)
{
	int	i;
	int	temp;
	t_node	*node;

	i = 0;
	node = stack->a_top;
	temp = -2147483648;

	while (node)
	{
		if (temp < node->content)
		{
			i++;
			temp = node->content;
		}
		node = node->next;
	}
	i = stack->a_size - i;
	while (i)
	{
		rra(stack);
		i--;
	}
}