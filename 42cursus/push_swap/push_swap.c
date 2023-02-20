/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:49:18 by soulee            #+#    #+#             */
/*   Updated: 2023/02/20 21:17:56 by soulee           ###   ########.fr       */
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
			if (array[i] > array[j])
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

	i = stack->a_size;
	array = list_to_array(stack);
	get_pivots(array, stack->a_size, &min_pivot, &max_pivot);
	while (i--)
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
	int		i;
	t_stack	*stack;

	if (argc < 2)
		wrap_exit(EXIT_SUCCESS, 0);
	stack = parse_arguments(argv);
	parition_stack(stack);
	hard_sort(stack);
	while (stack->b_size)
		greedy(stack);
	apply_rotate_last(stack);
	return (0);
}

// 100개 11
// 500개 5500
// 5개 12개
// 최적화 필요 ra하는걸 rra랑 나눠서 하기
// 보너스 구현하기
// 하드코딩하기