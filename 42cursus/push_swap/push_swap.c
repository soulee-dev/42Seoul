/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:49:18 by soulee            #+#    #+#             */
/*   Updated: 2023/02/21 23:06:46 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_sorted(int count)
{
	if (!count)
		wrap_exit(EXIT_SUCCESS, 0);
}

void	get_pivots(int	*array, int size, int *max_pivot, int *min_pivot)
{
	int		i;
	int		j;
	int		temp;
	int		count;

	i = -1;
	count = 0;
	while (++i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				count++;
			}
			j++;
		}
	}
	*max_pivot = array[size * 2 / 3];
	*min_pivot = array[size * 1 / 3];
	exit_sorted(count);
}

void	parition_stack(t_stack *stack)
{
	int		i;
	int		*array;
	int		max_pivot;
	int		min_pivot;

	i = stack->a_size;
	array = list_to_array(stack);
	get_pivots(array, stack->a_size, &max_pivot, &min_pivot);
	free(array);
	while (i-- && stack->a_size > 3)
	{
		if (max_pivot < stack->a_top->content)
			ra(stack);
		else
		{
			pb(stack);
			if (min_pivot > stack->b_top->content)
				rb(stack);
		}
	}
	while (stack->a_size > 3)
		pb(stack);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	if (argc < 2)
		wrap_exit(EXIT_SUCCESS, 0);
	stack = parse_arguments(argv);
	parition_stack(stack);
	hard_sort(stack, stack->a_top);
	while (stack->b_size)
		greedy(stack);
	apply_rotate_last(stack, stack->a_top);
	free_all(stack);
	return (0);
}

// "" 들어 오면 에러처리
