/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:37:30 by soulee            #+#    #+#             */
/*   Updated: 2023/02/13 20:34:18 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	wrap_atoi(t_node **node, const char *str)
{
	long long	num;
	long long	sign;

	num = 0;
	sign = 1;
	while (((int)(*str) >= 9 && (int)(*str) <= 13) || (int)(*str) == 32)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			num = num * 10 + (*str - '0');
			str++;
		}
		else
			wrap_exit(EXIT_ERROR, "INVALID ARGUMENT (NON INTEGER)");
	}
	if (sign * num > 2147483647 || sign * num < -2147483648)
		wrap_exit(EXIT_ERROR, "INVALID ARGUMENT (EXCEED INTEGER)");
	add_node_back(node, create_new_node(sign * num));
}

int	*list_to_array(t_stack *stack)
{
	t_node	*i;
	t_node	*j;
	int		k;
	int		*array;

	i = stack->a_top;
	j = stack->a_top;
	k = 0;
	array = malloc(stack->a_size);
	while (i)
	{
		array[k] = i->content;
		k++;
		i = i->next;
	}
	return (array);
}

t_stack	*parse_arguments(char **argv)
{
	int		i;
	int		*array;
	t_node	*list_a;
	char	**splitted_data;

	i = 1;
	list_a = 0;
	while (argv[i])
	{
		splitted_data = ft_split(argv[i], ' ');
		while (*splitted_data)
		{
			wrap_atoi(&list_a, *splitted_data);
			splitted_data++;
		}
		i++;
	}
	return (init_stack(list_a));
}