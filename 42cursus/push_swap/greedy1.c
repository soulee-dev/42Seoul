/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:59:22 by soulee            #+#    #+#             */
/*   Updated: 2023/02/16 19:12:33 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	count_instructions_b(t_stack *stack, int val, int *flag)
{
	int	i;
	t_node	*node;

	i = 0;
	node = stack->b_top;
	while (i < stack->b_size)
	{
		if (node->content == val)
			break ;
		i++;
		node = node->next;
	}
	if (i > stack->b_size / 2)
	{
		*flag = 1;
		return (stack->b_size - i);
	}
	else
	{
		*flag = 0;
		return (i);
	}
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
	int		a;
	int		b;
	int		sum;
	int		optimal;
	t_node	*node;
	int flag;

	pa(stack);
	pa(stack);
	pa(stack);
	printf("\n\n\n");
	printf("stack a: ");
	iter_node(stack->a_top);
	printf("stack b: ");
	iter_node(stack->b_top);
	sum = 2147483647;
	node = stack->b_top;

	optimal = 0;
	while (node)
	{
		a = count_instructions_a(stack, node->content);
		b = count_instructions_b(stack, node->content, &flag);
		if (sum > a + b)
		{
			sum = a + b;
			optimal = node->content;
		}

		printf("curr: %d, %d, %d, %d\n", node->content, a, b, a + b);

		node = node->next;
	}
	flag = 0;
	a = count_instructions_a(stack, optimal);
	b = count_instructions_b(stack, optimal, &flag);
	apply_rotate_a(stack, a);
	apply_rotate_b(stack, b, flag);
	pa(stack);
	printf("Optimal :%d\n", optimal);
	printf("stack b: ");
	iter_node(stack->b_top);
	// 최적 해를 구했으니 이제 적용해야 하는데?
	

}