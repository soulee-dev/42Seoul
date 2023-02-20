/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:29:43 by soulee            #+#    #+#             */
/*   Updated: 2023/02/20 22:33:09 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_rotate_a(t_stack *stack, int a, int flag)
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
	int		ra_cnt;
	int		rra_cnt;
	int		temp;
	t_node	*node;

	ra_cnt = 0;
	node = stack->a_top;
	temp = -2147483648;
	while (node)
	{
		if (temp < node->content)
		{
			ra_cnt++;
			temp = node->content;
		}
		node = node->next;
	}
	rra_cnt = stack->a_size - ra_cnt;
	if (ra_cnt > rra_cnt)
	{
		while (rra_cnt)
		{
			rra(stack);
			rra_cnt--;
		}
	}
	else
	{
		while (ra_cnt)
		{
			ra(stack);
			ra_cnt--;
		}
	}
}
