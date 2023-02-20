/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcoding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:36:47 by soulee            #+#    #+#             */
/*   Updated: 2023/02/20 20:54:30 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_sort(t_stack *stack)
{
	if (stack->a_size > 2)
	{
		if (stack->a_top->content > stack->a_top->next->content && stack->a_top->next->content < stack->a_top->next->next->content)
		{
			// case 1
			if (stack->a_top->content < stack->a_top->next->next->content)
				sa(stack);
			// case 3
			if (stack->a_top->content > stack->a_top->next->next->content)
				ra(stack);
		}
		if (stack->a_top->content < stack->a_top->next->content && stack->a_top->next->content > stack->a_top->next->next->content)
		{
			// case 4
			if (stack->a_top->content < stack->a_top->next->next->content)
			{
				sa(stack);
				ra(stack);
			}
			// case 5
			if (stack->a_top->content > stack->a_top->next->next->content)
				rra(stack);
		}
		if (stack->a_top->content > stack->a_top->next->content && stack->a_top->next->content > stack->a_top->next->next->content)
		{
			// case 2
			sa(stack);
			rra(stack);
		}
	}
}