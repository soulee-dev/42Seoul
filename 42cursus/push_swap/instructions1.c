/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:43:49 by soulee            #+#    #+#             */
/*   Updated: 2023/02/21 21:47:44 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	t_node	*temp;

	if (stack->a_size < 2)
		return ;
	temp = stack->a_top;
	stack->a_top = stack->a_top->next;
	temp->next = stack->a_top->next;
	stack->a_top->next = temp;
	ft_putendl_fd("sa", 1);
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
	ft_putendl_fd("sb", 1);
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
	ft_putendl_fd("pa", 1);
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
	ft_putendl_fd("pb", 1);
}

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
