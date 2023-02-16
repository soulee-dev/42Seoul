/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:49:18 by soulee            #+#    #+#             */
/*   Updated: 2023/02/16 21:24:52 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pivots(int	*array, int size, int *max_pivot, int *min_pivot)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[j])
		{
			if (array[i] < array[j])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
			j++;
		}
		i++;
	}
	*max_pivot = array[size * 2 / 3];
	*min_pivot = array[size * 1 / 3];
	free(array);
}

void	parition_stack(t_stack *stack)
{
	int		i;
	int		*array;
	int		min_pivot;
	int		max_pivot;

	i = 0;
	array = list_to_array(stack);
	get_pivots(array, stack->a_size, &min_pivot, &max_pivot);
	while (i < stack->a_size)
	{
		if (max_pivot < stack->a_top->content)
			ra(stack);
		else if (max_pivot >= stack->a_top->content
			&& min_pivot <= stack->a_top->content)
			pb(stack);
		else if (min_pivot > stack->a_top->content)
		{
			pb(stack);
			rb(stack);
		}
		i++;
	}
	// while (stack->a_size > 3)
	// 	pb(stack);
	while (stack->a_size)
		pb(stack);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*stack;

	if (argc < 2)
		wrap_exit(EXIT_SUCCESS, 0);
	stack = parse_arguments(argv);
	parition_stack(stack);
	while (stack->b_size)
		greedy(stack);
	apply_rotate_last(stack);
	return (0);
}
