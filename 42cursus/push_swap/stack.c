/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:43:49 by soulee            #+#    #+#             */
/*   Updated: 2023/02/13 21:47:47 by soulee           ###   ########.fr       */
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

// void	rra(t_stack *stack)
// {
// 	t_node	i;
// 	t_node	*temp;

// 	if (stack->a_size < 2)
// 		return ;
	 
// 	while (i)
// 	{
// 		if (!i->next)
// 			break ;
// 		i = i->next;
// 	}
// 	ft_putendl_fd("rra", 1);
// }

// void	rrb(t_stack *stack)
// {
// 	if (stack->b_size < 2)
// 		return ;
// 	ft_putendl_fd("rrb", 1);
// }

// void	rrr(t_stack *stack)
// {
// 	rra(stack);
// 	rrb(stack);
// 	ft_putendl_fd("rrr", 1);
// }
