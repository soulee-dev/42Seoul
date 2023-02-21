/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:55:27 by soulee            #+#    #+#             */
/*   Updated: 2023/02/21 23:10:03 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack *stack)
{
	if (stack->a_size < 2)
		return ;
	stack->a_bot->next = stack->a_top;
	stack->a_bot = stack->a_top;
	stack->a_top = stack->a_top->next;
	stack->a_bot->next = 0;
}

void	rb(t_stack *stack)
{
	if (stack->b_size < 2)
		return ;
	stack->b_bot->next = stack->b_top;
	stack->b_bot = stack->b_top;
	stack->b_top = stack->b_top->next;
	stack->b_bot->next = 0;
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}
