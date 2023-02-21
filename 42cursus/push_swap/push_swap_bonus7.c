/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:10:15 by soulee            #+#    #+#             */
/*   Updated: 2023/02/21 23:10:22 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_stack *stack)
{
	t_node	*i;
	t_node	*temp;
	t_node	*temp_next;

	if (stack->a_size < 2)
		return ;
	i = stack->a_top;
	while (i)
	{
		if (!i->next)
			break ;
		temp = i;
		i = i->next;
	}
	temp->next = 0;
	temp_next = stack->a_top;
	stack->a_top = stack->a_bot;
	stack->a_top->next = temp_next;
	stack->a_bot = temp;
}

void	rrb(t_stack *stack)
{
	t_node	*i;
	t_node	*temp;
	t_node	*temp_next;

	if (stack->b_size < 2)
		return ;
	i = stack->b_top;
	while (i)
	{
		if (!i->next)
			break ;
		temp = i;
		i = i->next;
	}
	temp->next = 0;
	temp_next = stack->b_top;
	stack->b_top = stack->b_bot;
	stack->b_top->next = temp_next;
	stack->b_bot = temp;
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
