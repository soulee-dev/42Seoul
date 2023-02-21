/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:54:42 by soulee            #+#    #+#             */
/*   Updated: 2023/02/21 23:01:37 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack *stack)
{
	t_node	*temp;

	if (stack->a_size < 2)
		return ;
	temp = stack->a_top;
	stack->a_top = stack->a_top->next;
	temp->next = stack->a_top->next;
	stack->a_top->next = temp;
}

void	sb(t_stack *stack)
{
	t_node	*temp;

	if (stack->b_size < 2)
		return ;
	temp = stack->b_top;
	stack->b_top = stack->b_top->next;
	temp->next = stack->b_top->next;
	stack->b_top->next = temp;
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}

void	pa(t_stack *stack)
{
	t_node	*temp;

	if (stack->b_size < 1)
		return ;
	temp = stack->a_top;
	stack->a_top = stack->b_top;
	stack->b_top = stack->b_top->next;
	stack->a_top->next = temp;
	stack->b_size--;
	stack->a_size++;
	if (!stack->a_bot)
		stack->a_bot = stack->a_top;
}

void	pb(t_stack *stack)
{
	t_node	*temp;

	if (stack->a_size < 1)
		return ;
	temp = stack->b_top;
	stack->b_top = stack->a_top;
	stack->a_top = stack->a_top->next;
	stack->b_top->next = temp;
	stack->a_size--;
	stack->b_size++;
	if (!stack->b_bot)
		stack->b_bot = stack->b_top;
}

void	ra(t_stack *stack)
{
	if (stack->a_size < 2)
		return ;
	stack->a_bot->next = stack->a_top;
	stack->a_bot = stack->a_top;
	stack->a_top = stack->a_top->next;
	stack->a_bot->next = 0;
}
