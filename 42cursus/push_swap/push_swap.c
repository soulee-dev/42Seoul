/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:49:18 by soulee            #+#    #+#             */
/*   Updated: 2023/02/20 22:38:05 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pivots(int	*array, int size, int *max_pivot, int *min_pivot)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
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
	int		max_pivot;
	int		min_pivot;

	i = stack->a_size;
	array = list_to_array(stack);
	get_pivots(array, stack->a_size, &max_pivot, &min_pivot);
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
	iter_node(stack->a_top);
	return (0);
}

// TODO 가끔씩 튀는 값이 있는데 이거는 명령어 합치는걸로 해결해보기
// TODO sort된 경우 아무것도 출력하지 않고 나가기
// TODO leak 확인하기
// TODO norm 확인하기