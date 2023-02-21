/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:29:46 by soulee            #+#    #+#             */
/*   Updated: 2023/02/21 21:53:56 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include "../libft/libft.h"
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

void	wrap_exit(int exit_code, char *error_message);

#endif