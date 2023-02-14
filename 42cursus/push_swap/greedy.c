/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:59:22 by soulee            #+#    #+#             */
/*   Updated: 2023/02/15 00:03:57 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// 가장 작은 b
int	count_instructions_node(t_node *node, int size, int val)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (node->content == val)
			break ;
		i++;
		node = node->next;
	}
	if (i > size / 2)
		return (size - i);
	else
		return (i);
}

int	count_instructions_b(t_stack *stack, int val)
{
	t_node	*node;

	node = stack->b_top;
	return (count_instructions_node(node, stack->b_size, val));
}

int	get_mid_index(t_node *node, int val)
{
	int	count;

	count = 0;
	while (node && (node->content > val))
	{
		count++;
		node = node->next;
	}
	while (node && (node->content < val))
	{
		count++;
		node = node->next;
	}
	return (count);
}

int	count_instructions_a(t_stack *stack, int val)
{
	int		count;
	t_node	*node;

	count = 0;
	node = stack->a_top;
	while (node)
	{
		if (node->content < val)
			count++;
		node = node->next;
	}
	if (count == 0 || count == stack->a_size)
	{
		node = stack->a_top;
		count = 1;
		while (node)
		{
			if (node->next && node->next->content > node->content)
			{
				node = node->next;
				count++;
			}
			else
				break;
		}
	}
		// return (count_instructions_node(stack->a_top, stack->a_size, val));
		// max or min
		// get index of highest value in stack a like counting instructions in b
	else
		count = (get_mid_index(stack->a_top, val));
	if (count == stack->a_size)
		return (0);
	return (count);
}

void	greedy(t_stack *stack)
{
	t_node	*node;
	
	pa(stack);
	pa(stack);
	pa(stack);
	printf("\n\n\n");
	printf("stack a: ");
	iter_node(stack->a_top);
	printf("stack b: ");
	iter_node(stack->b_top);
	node = stack->b_top;
	while (node)
	{
		printf("%d ", count_instructions_b(stack, node->content));
		node = node->next;
	}
	printf("\n");
	node = stack->b_top;
	while (node)
	{
		printf("%d ", count_instructions_a(stack, node->content));
		node = node->next;
	}
}