/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:26:59 by soulee            #+#    #+#             */
/*   Updated: 2023/02/14 16:28:19 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putendl_fd("rra", 1);
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
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	ft_putendl_fd("rrr", 1);
}