/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:29:46 by soulee            #+#    #+#             */
/*   Updated: 2023/02/22 17:12:30 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include "libft/libft.h"
# include "get_next_line_bonus.h"
# define EXIT_SUCCESS 0
# define EXIT_ERROR 1

typedef struct s_node {
	int				content;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	t_node	*a_top;
	t_node	*a_bot;
	int		a_size;
	t_node	*b_top;
	t_node	*b_bot;
	int		b_size;
}	t_stack;

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

t_stack	*init_stack(t_node *list_a);
void	wrap_atoi(t_node **node, const char *str);
void	wrap_exit(int exit_code, char *error_message);
void	free_split(char **strs, int size);
void	add_node_back(t_node **node, t_node *new);
t_node	*get_last_node(t_node *node);
int		get_list_size(t_node *node);
t_node	*create_new_node(int content);
t_stack	*parse_arguments(char **argv);
void	free_all(t_stack *stack);
#endif