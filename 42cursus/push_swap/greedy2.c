/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:29:43 by soulee            #+#    #+#             */
/*   Updated: 2023/02/16 19:13:02 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra인지 rra인지 확인하느 방법?

void	apply_rotate_a(t_stack *stack, int a)
{
	while (a)
	{
		ra(stack);
		a--; 
	}
}

void	apply_rotate_b(t_stack *stack, int b, int flag)
{
	while (b)
	{
		if (flag)
			rrb(stack);
		else
			rb(stack);
		b--;
	}
}