/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:29:43 by soulee            #+#    #+#             */
/*   Updated: 2023/02/21 17:20:16 by soulee           ###   ########.fr       */
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

void	rotate_last(t_stack *stack, int ra_cnt, int rra_cnt)
{
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

void	apply_rotate_last(t_stack *stack, t_node *node)
{
	int		ra_cnt;
	int		rra_cnt;
	int		temp;

	ra_cnt = 0;
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
	rotate_last(stack, ra_cnt, rra_cnt);
}

int	get_optimal_instructions(t_stack *stack, t_node *node)
{
	int		a;
	int		b;
	int		sum;
	int		flag;
	int		optimal;

	optimal = 0;
	sum = 2147483647;
	while (node)
	{
		a = count_instructions_a(stack, node->content);
		if (a >= stack->a_size / 2)
			a = stack->a_size - a;
		b = count_instructions_b(stack, node->content, &flag);
		if (sum > a + b)
		{
			sum = a + b;
			optimal = node->content;
		}
		node = node->next;
	}
	return (optimal);
}
