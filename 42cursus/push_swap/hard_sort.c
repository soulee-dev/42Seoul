/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:36:47 by soulee            #+#    #+#             */
/*   Updated: 2023/02/20 22:34:18 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_sort(t_stack *stack)
{
	t_node	*node;

	node = stack->a_top;
	if (stack->a_size > 2)
	{
		if (node->content > node->next->content && node->next->content < node->next->next->content)
		{
			if (node->content < node->next->next->content)
				sa(stack);
			if (node->content > node->next->next->content)
				ra(stack);
		}
		if (node->content < node->next->content && node->next->content > node->next->next->content)
		{
			if (node->content < node->next->next->content)
			{
				sa(stack);
				ra(stack);
			}
			if (node->content > node->next->next->content)
				rra(stack);
		}
		if (node->content > node->next->content && node->next->content > node->next->next->content)
		{
			sa(stack);
			rra(stack);
		}
	}
}
