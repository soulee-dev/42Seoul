/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:43:49 by soulee            #+#    #+#             */
/*   Updated: 2023/02/11 21:46:42 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(t_node *list_a)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	
	stack->a_top = list_a;
	stack->a_bot = get_last_node(list_a);
	stack->a_size = get_list_size(list_a);

	stack->b_top = 0;
	stack->b_bot = 0;
	stack->b_size = 0;
	
	return (stack);
}

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
}

// void	ra(t_stack *stack)
// {
	
// }

// void	rb(t_stack *stack)
// {
	
// }

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}

// void	rra(t_stack *stack)
// {
	
// }

// void	rrb(t_stack *stack)
// {
	
// }

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
