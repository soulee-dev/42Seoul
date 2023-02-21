/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:36:47 by soulee            #+#    #+#             */
/*   Updated: 2023/02/21 16:36:14 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_ra(t_stack *stack)
{
	sa(stack);
	ra(stack);
}

void	sa_rra(t_stack *stack)
{
	sa(stack);
	rra(stack);
}

void	hard_sort(t_stack *stack, t_node *node)
{
	if (stack->a_size > 2)
	{
		if (node->content > node->next->content
			&& node->next->content < node->next->next->content)
		{
			if (node->content < node->next->next->content)
				sa(stack);
			else if (node->content > node->next->next->content)
				ra(stack);
		}
		else if (node->content < node->next->content
			&& node->next->content > node->next->next->content)
		{
			if (node->content < node->next->next->content)
				sa_ra(stack);
			else if (node->content > node->next->next->content)
				rra(stack);
		}
		else if (node->content > node->next->content
			&& node->next->content > node->next->next->content)
			sa_rra(stack);
	}
}
