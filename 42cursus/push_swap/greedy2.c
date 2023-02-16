/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:29:43 by soulee            #+#    #+#             */
/*   Updated: 2023/02/16 21:24:45 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_rotate_a(t_stack *stack, int a)
{
	while (a)
	{
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
	temp = 0;

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