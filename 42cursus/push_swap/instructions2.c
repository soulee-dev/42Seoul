/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:26:59 by soulee            #+#    #+#             */
/*   Updated: 2023/02/21 23:03:02 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	if (stack->a_size < 2)
		return ;
	stack->a_bot->next = stack->a_top;
	stack->a_bot = stack->a_top;
	stack->a_top = stack->a_top->next;
	stack->a_bot->next = 0;
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *stack)
{
	if (stack->b_size < 2)
		return ;
	stack->b_bot->next = stack->b_top;
	stack->b_bot = stack->b_top;
	stack->b_top = stack->b_top->next;
	stack->b_bot->next = 0;
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	ft_putendl_fd("rr", 1);
}
